#ifndef ERTOOL_ERANAEVENTDATA_CXX
#define ERTOOL_ERANAEVENTDATA_CXX

#include "ERAnaEventdata.h"

namespace ertool {

  ERAnaEventdata::ERAnaEventdata(const std::string& name) : AnaBase(name)
  ,_edtree(nullptr)
  {
    delete _edtree;
    _edtree = new TTree("edtree","edt");
    _edtree->Branch("_eventid",&_eventid,"eventID/I");
    _edtree->Branch("_run",&_run,"run/I");
    _edtree->Branch("_subrun",&_subrun,"subrun/I");
    _edtree->Branch("_nshowers",&_nshowers,"nshowers/I");
    _edtree->Branch("_Eshr",&_Eshr,"eshr[100]/D");
    _edtree->Branch("_SPshr",&_SPshr,"spshr[50][3]/D");
    _edtree->Branch("_Dirshr",&_Dirshr,"dirshr[50][3]/D");
}

  void ERAnaEventdata::Reset()
  {}

  void ERAnaEventdata::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAnaEventdata::ProcessBegin()
  {}

  bool ERAnaEventdata::Analyze(const EventData &data, const ParticleGraph &graph)
  { 
	// basic info for the events
	_eventid = data.Event_ID();
	_run = data.Run();
	_subrun = data.SubRun();
	//just looking at all the shower objects in this events
	auto const& shrIDs = graph.GetParticleNodes(RecoType_t::kShower);
	_nshowers=shrIDs.size();
	// if nshowers==0 clear everything...there is no need to do this.. just make sure you are cutting nshowers!=0 in the tree
        for (unsigned int a = 0; a<shrIDs.size(); a++){
                auto const& shr = data.Shower(graph.GetParticle(shrIDs[a]).RecoID());
                auto spshr = shr.Start();
                auto dirshr = shr.Dir();
		std::cout<<" Energy"<< shr._energy<<std::endl;
		_Eshr[a] = shr._energy;
		for( unsigned int i=0; i <3;i++){
		_SPshr[a][i] = spshr[i];
		_Dirshr[a][i] = dirshr[i];
		}// for to fill out the xyz's
	}
	_edtree->Fill();

return true; }

  void ERAnaEventdata::ProcessEnd(TFile* fout)
   {
	_edtree->Write();
}

}

#endif
