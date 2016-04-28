#ifndef ERTOOL_ERANAMCEVENTDATA_CXX
#define ERTOOL_ERANAMCEVENTDATA_CXX

#include "ERAnaMCEventdata.h"

namespace ertool {

  ERAnaMCEventdata::ERAnaMCEventdata(const std::string& name) : AnaBase(name)
  {}

  void ERAnaMCEventdata::Reset()
  {}

  void ERAnaMCEventdata::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAnaMCEventdata::ProcessBegin()
  {}

  bool ERAnaMCEventdata::Analyze(const EventData &data, const ParticleGraph &graph)
  {

        auto mcgraph = MCParticleGraph();
        auto mceventdata = MCEventData();
        auto mcp =  mcgraph.GetParticleArray();
	// First decided if we have a single particle or neutrino event
	bool nuevt = false;
        for(auto const & m : mcp){ if(fabs(m.PdgCode())==14 || fabs(m.PdgCode())==12){std::cout<<"have nu sample"<<std::endl; nuevt = true;}}

	NodeID_t g1node_mc = -999;
        NodeID_t g2node_mc = -999;
	int g1node_mcdet = -999;
        int g2node_mcdet = -999;
	bool goodmcpair = true;
	// for ease of coding I will skip dalitz decay events
	for(auto const & m : mcp){
		if(m.PdgCode()==111){
			if(nuevt){ // need to ask if it is a generation 1. here we will look only at pi0's from the nucleus 
			    if( m.Generation()!=1) continue;
				}// if nuevt
	//here is the pi0
	//NodeID_t pi0node_mc = m.ID();
        std::vector<NodeID_t> kids_v = mcgraph.GetAllDescendantNodes(m.ID());
	// if kids size are 2?
	if(kids_v.size()!=2){ goodmcpair = false; continue;}

	        for(unsigned int a = 0; a <kids_v.size(); a++){
                if(g1node_mc== -999){ g1node_mc= kids_v[a]; g1node_mcdet = mcgraph.GetParticle(g1node_mc).RecoID();}
                else{g2node_mc = kids_v[a]; g2node_mcdet = mcgraph.GetParticle(g2node_mc).RecoID();}
                        }// for loop over kids
		}// if mpdg ==111
		}// loop over the mcparticles

if(goodmcpair){	
	// fill out some info about the showers
	if(g1node_mc>10 ||g2node_mc>10){// such a bad hack :(... but it works.. :) 
	
	std::cout<<"now we have 1  ids" <<g1node_mc<<std::endl;
	std::cout<<"now we have 2  ids" <<g2node_mc<<std::endl;
				}

	if(g1node_mcdet>0 ||g2node_mcdet>0){
	std::cout<<"now we have det 1  ids" <<g1node_mcdet<<std::endl;
	std::cout<<"now we have det 2  ids" <<g2node_mcdet<<std::endl;
				}


}
	

	



 return true; }

  void ERAnaMCEventdata::ProcessEnd(TFile* fout)
  {}

}

#endif
