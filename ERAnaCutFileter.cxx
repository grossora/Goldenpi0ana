#ifndef ERTOOL_ERANACUTFILETER_CXX
#define ERTOOL_ERANACUTFILETER_CXX

#include "ERAnaCutFileter.h"

namespace ertool {

  ERAnaCutFileter::ERAnaCutFileter(const std::string& name) : AnaBase(name)
  {}

  void ERAnaCutFileter::Reset()
  {}

  void ERAnaCutFileter::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAnaCutFileter::ProcessBegin()
  {}

  bool ERAnaCutFileter::Analyze(const EventData &data, const ParticleGraph &graph)
  { 
	// This will be dumb... but should work
	// used to filter out files when writing output root files
	auto particles = graph.GetParticleArray();
	bool goodpi0 = false; 
	// a particle must have atleast a pi0 and 2 photons
	if(particles.size()<3) return false;
	for(auto const& p: particles){
		if(p.PdgCode()==111){ 
		// pass if there are cuts	
			if(p.Mass()>_MaxMass||p.Mass()<_MinMass){ break;}
			std::cout<<"mass " << p.Mass()<<std::endl;	
			goodpi0 = true;
		}// if pi0 
	}// for loop over particles 
	if(!goodpi0) return false;	

	return true; 
  }

  void ERAnaCutFileter::ProcessEnd(TFile* fout)
  {}

}

#endif
