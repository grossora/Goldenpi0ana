#ifndef ERTOOL_ERANAPHOTONANA_CXX
#define ERTOOL_ERANAPHOTONANA_CXX

#include "ERAnaPhotonana.h"

namespace ertool {

  ERAnaPhotonana::ERAnaPhotonana(const std::string& name) : AnaBase(name)
  ,_showertree(nullptr)
  ,_Edepresnshowers(nullptr)
  ,_Edepres(nullptr)
  {
	delete _showertree;
	_showertree = new TTree("stree","stree");
	_showertree->Branch("energy",&_energy,"energy/D");
	_showertree->Branch("energydep",&_energydep,"energydep/D");
	_showertree->Branch("x",&_x,"x/D");
	_showertree->Branch("y",&_y,"y/D");
	_showertree->Branch("z",&_z,"z/D");
	_showertree->Branch("px",&_px,"px/D");
	_showertree->Branch("py",&_py,"py/D");
	_showertree->Branch("pz",&_pz,"pz/D");
	_showertree->Branch("xdep",&_xdep,"xdep/D");
	_showertree->Branch("ydep",&_ydep,"ydep/D");
	_showertree->Branch("zdep",&_zdep,"zdep/D");
	_showertree->Branch("pxdep",&_pxdep,"pxdep/D");
	_showertree->Branch("pydep",&_pydep,"pydep/D");
	_showertree->Branch("pzdep",&_pzdep,"pzdep/D");

	_showertree->Branch("nshowers",&_nshowers,"nshowers/I");
	_showertree->Branch("renergy",&_renergy,"renergy/D");
	_showertree->Branch("rx",&_rx,"rx/D");
	_showertree->Branch("ry",&_ry,"ry/D");
	_showertree->Branch("rz",&_rz,"rz/D");
	_showertree->Branch("rpx",&_rpx,"rpx/D");
	_showertree->Branch("rpy",&_rpy,"rpy/D");
	_showertree->Branch("rpz",&_rpz,"rpz/D");
	
	delete _Edepresnshowers;
	_Edepresnshowers =  new TH2D("EDep", "Single Photon Sample;Number of showers; E Resolution",7,0,7,20,-1.,0.2);

	delete _Edepres;
	_Edepres =  new TH1D("EDepres", "Single Photon Deposit Resolution; Resolution; Events",40,-1.,0.2);
}

  void ERAnaPhotonana::Reset()
  {}

  void ERAnaPhotonana::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAnaPhotonana::ProcessBegin()
  {
}

  bool ERAnaPhotonana::Analyze(const EventData &data, const ParticleGraph &graph)
  { 

	// Find the MC information 
	auto mcgraph = MCParticleGraph();
	auto mceventdata = MCEventData();
	auto mcp =  mcgraph.GetParticleArray();
	auto particles = graph.GetParticleArray();
	
	if(mcp.size()!=1) return true;
	
	auto mcgamma = mcgraph.GetParticle(mcp[0].ID());
	std::cout<<" vertex "<<mcgamma.Vertex()[0]<<std::endl;
	_x = mcgamma.Vertex()[0];
	_y = mcgamma.Vertex()[1];
	_z = mcgamma.Vertex()[2];
	_energy = mcgamma.Momentum().Length();
	_px = mcgamma.Momentum()[0];
	_py = mcgamma.Momentum()[1];
	_pz = mcgamma.Momentum()[2];
	
	if(mcgamma.RecoID()<0 || mcgamma.RecoID()>100000) return true;
        auto mcgammadep = mceventdata.Shower(mcgamma.RecoID());
	_energydep = mcgammadep._energy;
	_xdep = mcgammadep.Start()[0];
	_ydep = mcgammadep.Start()[1];
	_zdep = mcgammadep.Start()[2];
	_pxdep = mcgammadep.Dir()[0];
	_pydep = mcgammadep.Dir()[1];
	_pzdep = mcgammadep.Dir()[2];



	if(mcp.size()==1) counter++;
		

	// 
       auto const& shrIDs = graph.GetParticleNodes(RecoType_t::kShower);
        _nshowers=shrIDs.size();
        // if nshowers==0 clear everything...there is no need to do this.. just make sure you are cutting nshowers!=0 in the tree
        for (unsigned int a = 0; a<shrIDs.size(); a++){
                auto const& shr = data.Shower(graph.GetParticle(shrIDs[a]).RecoID());
                auto spshr = shr.Start();
                auto dirshr = shr.Dir();
                _renergy = shr._energy;
                _rx = spshr[0];
                _ry = spshr[1];
                _rz = spshr[2];
                _rpx = dirshr[0];
                _rpy = dirshr[1];
                _rpz = dirshr[2];
		
	_showertree->Fill();
	// 
	double depres = (_renergy-_energydep)/_energydep;
	_Edepresnshowers->Fill(_nshowers,depres);
        }

	if(_nshowers==1) _Edepres->Fill((_renergy-_energydep)/_energydep);







return true; }

  void ERAnaPhotonana::ProcessEnd(TFile* fout)
  {
	std::cout<<"Counter " << counter<<std::endl;
	_showertree->Write();
	_Edepresnshowers->Write();
	_Edepres->SetLineColor(4);
	_Edepres->SetFillColor(4);
	_Edepres->SetFillStyle(3004);
	_Edepres->Write();
}

}

#endif
