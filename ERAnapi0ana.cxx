#ifndef ERTOOL_ERANAPI0ANA_CXX
#define ERTOOL_ERANAPI0ANA_CXX

#include "ERAnapi0ana.h"

namespace ertool {
	ERAnapi0ana::ERAnapi0ana(const std::string& name) : AnaBase(name)
	,_mctree(nullptr)
	,_fulltree(nullptr)
	,_recomass(nullptr)
	,_fitrecomass(nullptr)
	,_emresdep(nullptr)
	,_angleresdep(nullptr)
	,_emres(nullptr)
	,_angleres(nullptr)
	,_angleresDEG(nullptr)
	{
		delete _mctree;
		_mctree = new TTree("mctree","mct");
		_mctree->Branch("_pi0_x",&_pi0_x,"x/D");
		_mctree->Branch("_pi0_y",&_pi0_y,"y/D");
		_mctree->Branch("_pi0_z",&_pi0_z,"z/D");
		_mctree->Branch("_pi0_p",&_pi0_p,"p/D");
		_mctree->Branch("_pi0_px",&_pi0_px,"px/D");
		_mctree->Branch("_pi0_py",&_pi0_py,"py/D");
		_mctree->Branch("_pi0_pz",&_pi0_pz,"pz/D");
		_mctree->Branch("_g1_y",&_g1_y,"g1y/D");
		_mctree->Branch("_g1_z",&_g1_z,"g1z/D");
		_mctree->Branch("_g1_p",&_g1_p,"g1p/D");
		_mctree->Branch("_g1_px",&_g1_px,"g1px/D");
		_mctree->Branch("_g1_py",&_g1_py,"g1py/D");
		_mctree->Branch("_g1_pz",&_g1_pz,"g1pz/D");
		_mctree->Branch("_g2_y",&_g2_y,"g2y/D");
		_mctree->Branch("_g2_z",&_g2_z,"g2z/D");
		_mctree->Branch("_g2_p",&_g2_p,"g2p/D");
		_mctree->Branch("_g2_px",&_g2_px,"g2px/D");
		_mctree->Branch("_g2_py",&_g2_py,"g2py/D");
		_mctree->Branch("_g2_pz",&_g2_pz,"g2pz/D");
		_mctree->Branch("_g1g2_p",&_g1g2_p,"g1g2p/D");
		_mctree->Branch("_g1g2_angle",&_g1g2_angle,"g1g2angle/D");
	// dep
		_mctree->Branch("_g1dep_x",&_g1dep_x,"g1depx/D");
		_mctree->Branch("_g1dep_y",&_g1dep_y,"g1depy/D");
		_mctree->Branch("_g1dep_z",&_g1dep_z,"g1depz/D");
		_mctree->Branch("_g1dep_p",&_g1dep_p,"g1depp/D");
		_mctree->Branch("_g1dep_px",&_g1dep_px,"g1deppx/D");
		_mctree->Branch("_g1dep_py",&_g1dep_py,"g1deppy/D");
		_mctree->Branch("_g1dep_pz",&_g1dep_pz,"g1deppz/D");
		_mctree->Branch("_g2dep_y",&_g2dep_y,"g2depy/D");
		_mctree->Branch("_g2dep_z",&_g2dep_z,"g2depz/D");
		_mctree->Branch("_g2dep_p",&_g2dep_p,"g2depp/D");
		_mctree->Branch("_g2dep_px",&_g2dep_px,"g2deppx/D");
		_mctree->Branch("_g2dep_py",&_g2dep_py,"g2deppy/D");
		_mctree->Branch("_g2dep_pz",&_g2dep_pz,"g2deppz/D");
		_mctree->Branch("_g1g2dep_p",&_g1g2dep_p,"g1g2depp/D");
		_mctree->Branch("_g1g2dep_angle",&_g1g2dep_angle,"g1g2depangle/D");

		delete _fulltree;
		_fulltree = new TTree("fulltree","fullt");
	// mc part
		_fulltree->Branch("_pi0_x",&_pi0_x,"x/D");
		_fulltree->Branch("_pi0_y",&_pi0_y,"y/D");
		_fulltree->Branch("_pi0_z",&_pi0_z,"z/D");
		_fulltree->Branch("_pi0_p",&_pi0_p,"p/D");
		_fulltree->Branch("_pi0_px",&_pi0_px,"px/D");
		_fulltree->Branch("_pi0_py",&_pi0_py,"py/D");
		_fulltree->Branch("_pi0_pz",&_pi0_pz,"pz/D");
		_fulltree->Branch("_g1_x",&_g1_x,"g1x/D");
		_fulltree->Branch("_g1_y",&_g1_y,"g1y/D");
		_fulltree->Branch("_g1_z",&_g1_z,"g1z/D");
		_fulltree->Branch("_g1_p",&_g1_p,"g1p/D");
		_fulltree->Branch("_g1_px",&_g1_px,"g1px/D");
		_fulltree->Branch("_g1_py",&_g1_py,"g1py/D");
		_fulltree->Branch("_g1_pz",&_g1_pz,"g1pz/D");
		_fulltree->Branch("_g2_x",&_g2_x,"g2x/D");
		_fulltree->Branch("_g2_y",&_g2_y,"g2y/D");
		_fulltree->Branch("_g2_z",&_g2_z,"g2z/D");
		_fulltree->Branch("_g2_p",&_g2_p,"g2p/D");
		_fulltree->Branch("_g2_px",&_g2_px,"g2px/D");
		_fulltree->Branch("_g2_py",&_g2_py,"g2py/D");
		_fulltree->Branch("_g2_pz",&_g2_pz,"g2pz/D");
		_fulltree->Branch("_g1g2_p",&_g1g2_p,"g1g2p/D");
		_fulltree->Branch("_g1g2_angle",&_g1g2_angle,"g1g2angle/D");
	// dep
		_fulltree->Branch("_g1dep_x",&_g1dep_x,"g1depx/D");
		_fulltree->Branch("_g1dep_y",&_g1dep_y,"g1depy/D");
		_fulltree->Branch("_g1dep_z",&_g1dep_z,"g1depz/D");
		_fulltree->Branch("_g1dep_p",&_g1dep_p,"g1depp/D");
		_fulltree->Branch("_g1dep_px",&_g1dep_px,"g1deppx/D");
		_fulltree->Branch("_g1dep_py",&_g1dep_py,"g1deppy/D");
		_fulltree->Branch("_g1dep_pz",&_g1dep_pz,"g1deppz/D");
		_fulltree->Branch("_g2dep_x",&_g2dep_x,"g2depx/D");
		_fulltree->Branch("_g2dep_y",&_g2dep_y,"g2depy/D");
		_fulltree->Branch("_g2dep_z",&_g2dep_z,"g2depz/D");
		_fulltree->Branch("_g2dep_p",&_g2dep_p,"g2depp/D");
		_fulltree->Branch("_g2dep_px",&_g2dep_px,"g2deppx/D");
		_fulltree->Branch("_g2dep_py",&_g2dep_py,"g2deppy/D");
		_fulltree->Branch("_g2dep_pz",&_g2dep_pz,"g2deppz/D");
		_fulltree->Branch("_g1g2dep_p",&_g1g2dep_p,"g1g2depp/D");
		_fulltree->Branch("_g1g2dep_angle",&_g1g2dep_angle,"g1g2depangle/D");
	// reco  part
		_fulltree->Branch("_rpi0_x",&_rpi0_x,"x/D");
		_fulltree->Branch("_rpi0_y",&_rpi0_y,"y/D");
		_fulltree->Branch("_rpi0_z",&_rpi0_z,"z/D");
		_fulltree->Branch("_rpi0_p",&_rpi0_p,"p/D");
		_fulltree->Branch("_rpi0_px",&_rpi0_px,"px/D");
		_fulltree->Branch("_rpi0_py",&_rpi0_py,"py/D");
		_fulltree->Branch("_rpi0_pz",&_rpi0_pz,"pz/D");
		_fulltree->Branch("_rg1_x",&_rg1_x,"rg1x/D");
		_fulltree->Branch("_rg1_y",&_rg1_y,"rg1y/D");
		_fulltree->Branch("_rg1_z",&_rg1_z,"rg1z/D");
		_fulltree->Branch("_rg1_p",&_rg1_p,"rg1p/D");
		_fulltree->Branch("_rg1_px",&_rg1_px,"rg1px/D");
		_fulltree->Branch("_rg1_py",&_rg1_py,"rg1py/D");
		_fulltree->Branch("_rg1_pz",&_rg1_pz,"rg1pz/D");
		_fulltree->Branch("_rg2_x",&_rg2_x,"rg2x/D");
		_fulltree->Branch("_rg2_y",&_rg2_y,"rg2y/D");
		_fulltree->Branch("_rg2_z",&_rg2_z,"rg2z/D");
		_fulltree->Branch("_rg2_p",&_rg2_p,"rg2p/D");
		_fulltree->Branch("_rg2_px",&_rg2_px,"rg2px/D");
		_fulltree->Branch("_rg2_py",&_rg2_py,"rg2py/D");
		_fulltree->Branch("_rg2_pz",&_rg2_pz,"rg2pz/D");
		_fulltree->Branch("_rg1rg2_p",&_rg1rg2_p,"rg1rg2p/D");
		_fulltree->Branch("_rg1rg2_angle",&_rg1rg2_angle,"rg1rg2angle/D");
	// dep
		_fulltree->Branch("_rg1dep_x",&_rg1dep_x,"rg1depx/D");
		_fulltree->Branch("_rg1dep_y",&_rg1dep_y,"rg1depy/D");
		_fulltree->Branch("_rg1dep_z",&_rg1dep_z,"rg1depz/D");
		_fulltree->Branch("_rg1dep_p",&_rg1dep_p,"rg1depp/D");
		_fulltree->Branch("_rg1dep_px",&_rg1dep_px,"rg1deppx/D");
		_fulltree->Branch("_rg1dep_py",&_rg1dep_py,"rg1deppy/D");
		_fulltree->Branch("_rg1dep_pz",&_rg1dep_pz,"rg1deppz/D");
		_fulltree->Branch("_rg2dep_y",&_rg2dep_y,"rg2depy/D");
		_fulltree->Branch("_rg2dep_z",&_rg2dep_z,"rg2depz/D");
		_fulltree->Branch("_rg2dep_p",&_rg2dep_p,"rg2depp/D");
		_fulltree->Branch("_rg2dep_px",&_rg2dep_px,"rg2deppx/D");
		_fulltree->Branch("_rg2dep_py",&_rg2dep_py,"rg2deppy/D");
		_fulltree->Branch("_rg2dep_pz",&_rg2dep_pz,"rg2deppz/D");
		_fulltree->Branch("_rg1rg2dep_p",&_rg1rg2dep_p,"rg1rg2depp/D");
		_fulltree->Branch("_rg1rg2dep_angle",&_rg1rg2dep_angle,"rg1rg2depangle/D");
// histogram plots 
		delete _recomass;
		_recomass = new TH1D("recomass","#pi^{0} mass; MeV; Events ",60,0,600);
		delete _fitrecomass;
		_fitrecomass = new TH1D("fitrecomass","#pi^{0} mass; MeV; Events ",60,0,600);
		delete _emres;
		_emres = new TH1D("emres"," sqrt(EE) resolution; Energy Resolution; Events ",50,-2,2);
		delete _angleres;
		_angleres = new TH1D("angleres"," angle resolution; Opening Angle Resolution; Events ",50,-4,4);
		delete _angleresDEG;
		_angleresDEG = new TH1D("angleresDEG"," angle resolution; Opening Angle Resolution; Events ",50,-4,4);
		delete _emresdep;
		_emresdep = new TH1D("emresdep"," sqrt(EEdep) resolution; Energy Resolution ; Events ",50,-2,2);
		delete _angleresdep;
		_angleresdep = new TH1D("angleresdep"," angledep resolution; Opening Angle Resolution; Events ",50,-4,4);
	}

	void ERAnapi0ana::Reset()
	{}

	void ERAnapi0ana::AcceptPSet(const ::fcllite::PSet& cfg)
	{}

	void ERAnapi0ana::ProcessBegin()
	{}

	bool ERAnapi0ana::Analyze(const EventData &data, const ParticleGraph &graph)
	{ 
	// Find the MC information 
		auto mcgraph = MCParticleGraph();
		auto mceventdata = MCEventData();
		auto mcp =  mcgraph.GetParticleArray();
		auto particles = graph.GetParticleArray();
	/////////////////////////////
	// Need the MC particle nodes
	/////////////////////////////
		NodeID_t pi0node_mc = -999;
	// Need the MC-Truth showers 
		NodeID_t g1node_mc = -999;
		NodeID_t g2node_mc = -999;
	// Need the MC-Det Showers
		int g1node_mcdet = -999;
		int g2node_mcdet = -999;
	// bool set?
		bool g1bool_mc = false;
		bool g2bool_mc  = false;
		
	/////////////////////////////
	// Need the reco particle nodes
	/////////////////////////////
		NodeID_t pi0node_r = -999;
	// Need the r-Truth showers 
		NodeID_t g1node_r = -999;
		NodeID_t g2node_r = -999;
	// Need the r-Det Showers
		NodeID_t g1node_rdet = -999;
		NodeID_t g2node_rdet = -999;
	// bool set?
		bool g1bool_r = false;
		bool g2bool_r = false;

	// MC Find the pi0 and fill out the nodes
		for(auto const & m : mcp){
//	if(m.PdgCode()==111 &&  m.Generation()==1){
			if(m.PdgCode()==111 ){
				pi0node_mc = m.ID();
				std::vector<NodeID_t> kids_v = mcgraph.GetAllDescendantNodes(m.ID());
		// loop over the kids and fill them.
		// Figure out how to deal with Dalitz... For now just ignore 
				if(kids_v.size()!=2) return true;
				for(unsigned int a = 0; a <kids_v.size(); a++){
					if(!g1bool_mc){ g1node_mc= kids_v[a]; 
					g1node_mcdet = mcgraph.GetParticle(g1node_mc).RecoID();
					 g1bool_mc=true;}
					else{g2node_mc= kids_v[a]; g2node_mcdet = mcgraph.GetParticle(g2node_mc).RecoID(); g2bool_mc=true;}
			}// for loop over kids
		}// if pi0 and gen 1 
	}// Loop over the MCparticle

	// Fill out the nodes for the reco pi0 
	for(auto const & p : particles){
		if(p.PdgCode()==111){
			pi0node_r = p.ID();
			std::vector<NodeID_t> kids_v = graph.GetAllDescendantNodes(p.ID());
		// loop over the kids and fill them.
			for(unsigned int a = 0; a <kids_v.size(); a++){
				if(!g1bool_r){ g1node_r= kids_v[a]; g1node_rdet = graph.GetParticle(g1node_r).RecoID(); g1bool_r=true;}
				else{g2node_r = kids_v[a]; g2node_rdet = graph.GetParticle(g2node_r).RecoID(); g2bool_r=true;}
			}// for loop over kids
		}// if pi0 and gen 1 
	}// Loop over the MCparticle


// This needs to be sorted and cleaned up RG.
	bool gmc = true;
	bool gmcdep = true;
	bool gr = true;
if(g1node_mc>10000 || g2node_mc>10000) gmc = false;// horrible horrible hack
if(g1node_mcdet<0  || g2node_mcdet<0) gmcdep = false;// horrible horrible hack

// Start to fill a tree with usefull info
	////////////////////
	// Fill out mc vars 
	////////////////////
auto mcpi0 = mcgraph.GetParticle(pi0node_mc);	
auto mcg1 = mcgraph.GetParticle(g1node_mc);	
auto mcg2 = mcgraph.GetParticle(g2node_mc);	
	// mcpi0 info
_pi0_x = mcpi0.Vertex()[0];
_pi0_y = mcpi0.Vertex()[1];
_pi0_z = mcpi0.Vertex()[2];
_pi0_p = mcpi0.Momentum().Length();
_pi0_px = mcpi0.Momentum()[0];
_pi0_py = mcpi0.Momentum()[1];
_pi0_pz = mcpi0.Momentum()[2];

	// mc gammas
	// mcgamma 1 info
_g1_x = mcg1.Vertex()[0];
_g1_y = mcg1.Vertex()[1];
_g1_z = mcg1.Vertex()[2];
_g1_p = mcg1.Momentum().Length();
_g1_px = mcg1.Momentum()[0];
_g1_py = mcg1.Momentum()[1];
_g1_pz = mcg1.Momentum()[2];
	// mcgamma 2 info
_g2_x = mcg2.Vertex()[0];
_g2_y = mcg2.Vertex()[1];
_g2_z = mcg2.Vertex()[2];
_g2_p = mcg2.Momentum().Length();
_g2_px = mcg2.Momentum()[0];
_g2_py = mcg2.Momentum()[1];
_g2_pz = mcg2.Momentum()[2];
	// mcgamma 1-2 relations
_g1g2_p = mcg1.Momentum().Length()*mcg2.Momentum().Length();
_g1g2_angle = mcg1.Momentum().Angle(mcg2.Momentum());

	// mc gammas Det shower object
	// mcgamma 1 info
if(gmcdep){
	auto mcg1dep = mceventdata.Shower(g1node_mcdet);	
	auto mcg2dep = mceventdata.Shower(g2node_mcdet);	
	_g1dep_x = mcg1dep.Start()[0];
	_g1dep_y = mcg1dep.Start()[1];
	_g1dep_z = mcg1dep.Start()[2];
	_g1dep_p = mcg1dep._energy;
	_g1dep_px = mcg1dep.Dir()[0];
	_g1dep_py = mcg1dep.Dir()[1];
	_g1dep_pz = mcg1dep.Dir()[2];
	// mcgamma 2 info
	_g2dep_x = mcg2dep.Start()[0];
	_g2dep_y = mcg2dep.Start()[1];
	_g2dep_z = mcg2dep.Start()[2];
	_g2dep_p = mcg2dep._energy;
	_g2dep_px = mcg2dep.Dir()[0];
	_g2dep_py = mcg2dep.Dir()[1];
	_g2dep_pz = mcg2dep.Dir()[2];
	// mcgamma 1-2 relations
	_g1g2dep_p = mcg1dep._energy*mcg2dep._energy;
	_g1g2dep_angle = mcg1dep.Dir().Angle(mcg2dep.Dir());
}

// Fill Trees 
//if( gmc) _mctree->Fill();
if(gmcdep && gmc) _mctree->Fill();

// Now we have filled the MC... lets move on to reco
if(g1node_r>10000 || g2node_r>10000 )	gr = false; // this is the wrong hack... but it works for now.

	/////////////////////////////////////
	//Fill out reco vars 
	/////////////////////////////////////
if(gr){
	auto rpi0 = graph.GetParticle(pi0node_r);	
	auto rg1 = graph.GetParticle(g1node_r);	
	auto rg2 = graph.GetParticle(g2node_r);	
	auto rg1dep = data.Shower(g1node_rdet);	
	auto rg2dep = data.Shower(g2node_rdet);	

        // rpi0 info
	_rpi0_x = rpi0.Vertex()[0];
	_rpi0_y = rpi0.Vertex()[1];
	_rpi0_z = rpi0.Vertex()[2];
	_rpi0_p = rpi0.Momentum().Length();
	_rpi0_px = rpi0.Momentum()[0];
	_rpi0_py = rpi0.Momentum()[1];
	_rpi0_pz = rpi0.Momentum()[2];

	// mc gammas
	// mcgamma 1 info
	_rg1_x = rg1.Vertex()[0];
	_rg1_y = rg1.Vertex()[1];
	_rg1_z = rg1.Vertex()[2];
	_rg1_p = rg1.Momentum().Length();
	_rg1_px = rg1.Momentum()[0];
	_rg1_py = rg1.Momentum()[1];
	_rg1_pz = rg1.Momentum()[2];
	// rgamma 2 info
	_rg2_x = rg2.Vertex()[0];
	_rg2_y = rg2.Vertex()[1];
	_rg2_z = rg2.Vertex()[2];
	_rg2_p = rg2.Momentum().Length();
	_rg2_px = rg2.Momentum()[0];
	_rg2_py = rg2.Momentum()[1];
	_rg2_pz = rg2.Momentum()[2];
	// rgamma 1-2 relations
	_rg1rg2_p = rg1.Momentum().Length()*rg2.Momentum().Length();
	_rg1rg2_angle = rg1.Momentum().Angle(rg2.Momentum());


	// r gammas Det shower object
	// rgamma 1 info
	_rg1dep_x = rg1dep.Start()[0];
	_rg1dep_y = rg1dep.Start()[1];
	_rg1dep_z = rg1dep.Start()[2];
	_rg1dep_p = rg1dep._energy;
	_rg1dep_px = rg1dep.Dir()[0];
	_rg1dep_py = rg1dep.Dir()[1];
	_rg1dep_pz = rg1dep.Dir()[2];
	// rgamma 2 info
	_rg2dep_x = rg2dep.Start()[0];
	_rg2dep_y = rg2dep.Start()[1];
	_rg2dep_z = rg2dep.Start()[2];
	_rg2dep_p = rg2dep._energy;
	_rg2dep_px = rg2dep.Dir()[0];
	_rg2dep_py = rg2dep.Dir()[1];
	_rg2dep_pz = rg2dep.Dir()[2];
	// rgamma 1-2 relations
	_rg1rg2dep_p = rg1dep._energy*rg2dep._energy;
	_rg1rg2dep_angle = rg1dep.Dir().Angle(rg2dep.Dir());
}

if(gmcdep && gmc && gr) _fulltree->Fill();


//////////////////////
//  reco-mctruth hists
// Here we can put together 
// some standard metric histos
//////////////////////
// Mass
if(gr){
	double recomass = sqrt(2*_rg1_p*_rg2_p*(1-cos(_rg1rg2_angle)));
	_recomass->Fill(recomass);
//fit Mass
	// these are hard coded for fun
//	double fitg1 = ((1-0.534)*_rg1_p + 104.);// working fit
//	double fitg2 = ((1-0.534)*_rg2_p + 104.);// working fit
//	
	double fitg1 = ((0.529)*_rg1_p +100.19 );// working fit
	double fitg2 =  ((0.529)*_rg2_p +100.19);// working fit
	//double fitg1 = ((0.589)*_rg1_p +111.19 );// working fit
	//double fitg2 =  ((0.589)*_rg2_p +111.19);// working fit
//	double fitg1 = ((0.253)*_rg1_p +266.317 );// working fit
//	double fitg2 =  ((0.253)*_rg2_p +266.317);// working fit
	//double fitg1 = ((1-0.333)*_rg1_p + 144.77);
	//double fitg2 = ((1-0.333)*_rg2_p + 144.77);
	double fitrecomass = sqrt(2.*fitg1*fitg2*(1.-cos(_rg1rg2_angle)));
	//double fitrecomass = sqrt(2*_rg1_p*_rg2_p*(1-cos(_rg1rg2_angle)));
	_fitrecomass->Fill(fitrecomass);
	}// if we have reconstructed


if(gmcdep && gmc && gr){
	// hists 
	// sqrt(E1E2) res 
	double fitg1 = ((0.589)*_rg1_p +104.19 );// working fit
	double fitg2 =  ((0.589)*_rg2_p +104.19);// working fit
        double EEReco = sqrt(fitg1*fitg2);
        //double EEReco = sqrt(_rg1_p*_rg2_p);
        double EEDep = sqrt(_g1dep_p*_g2dep_p);
        double EE = sqrt(_g1_p*_g2_p);
	double EEresdep = (EEDep - EEReco)/(EEDep);
	double EEres = (EE - EEReco)/(EE);
	double AngleResdep =  ((1-cos(_g1g2dep_angle)) - (1-cos(_rg1rg2_angle)))/((1-cos(_g1g2dep_angle)));
	double AngleRes =  ((1-cos(_g1g2_angle)) - (1-cos(_rg1rg2_angle)))/((1-cos(_g1g2_angle)));
	//double AngleResdep =  (_g1g2dep_angle - _rg1rg2_angle)/(_g1g2dep_angle);
	double AngleResDEG =(_g1g2_angle*180./3.14159265 - _rg1rg2_angle*180./3.14159265)/(_g1g2_angle*180./3.14159265);
	_emresdep->Fill(EEresdep);
	_angleresdep->Fill(AngleResdep);
	_emres->Fill(EEres);
	_angleres->Fill(AngleRes);
	_angleresDEG->Fill(AngleResDEG);
	
	}



	return true; }

	void ERAnapi0ana::ProcessEnd(TFile* fout)
	{
		_mctree->Write();
		_fulltree->Write();
		_recomass->Write();
		_fitrecomass->Write();
		_emres->Write();
		_angleres->Write();
		_emresdep->Write();
		_angleresdep->Write();
		_angleresDEG->Write();
	}

}

#endif
