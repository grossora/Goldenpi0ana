#ifndef ERTOOL_ERANAEVENTBYEVENT_CXX
#define ERTOOL_ERANAEVENTBYEVENT_CXX

#include "ERAnaEventByEvent.h"

namespace ertool {

  ERAnaEventByEvent::ERAnaEventByEvent(const std::string& name) : AnaBase(name)
  {}

  void ERAnaEventByEvent::Reset()
  {}

  void ERAnaEventByEvent::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAnaEventByEvent::ProcessBegin()
  {}

  bool ERAnaEventByEvent::Analyze(const EventData &data, const ParticleGraph &graph)
  { 



std::cout<<"Start Of Event:\n\tRun:"<<data.Run()<<"\n\tSubrun:"<<data.SubRun()<<"\n\tEvent:"<<data.Event_ID()<<std::endl;



                auto particles = graph.GetParticleArray();


                NodeID_t gnodeA = -999;
                NodeID_t gnodeB = -999;

        for(auto const & p : particles){
                if(p.PdgCode()==111){
                       // pi0node_r = p.ID();
                        std::vector<NodeID_t> kids_v = graph.GetAllDescendantNodes(p.ID());
                // loop over the kids and fill them.
                        for(unsigned int a = 0; a <kids_v.size(); a++){
                                if(gnodeB== -999 && gnodeA!= -999){ gnodeB = graph.GetParticle(kids_v[a]).RecoID();}
                                if(gnodeA== -999){ gnodeA = graph.GetParticle(kids_v[a]).RecoID();}
                        }// for loop over kids
                }// if pi0 and gen 1 
        }// Loop over the MCparticle



if(gnodeA==-999 || gnodeB==-999){ std::cout<<"\t\tEVENT DID NOT RECONSTRUCT A GOOD PI0.... Better luck next time :)\n\n"<<std::endl; return true;}
	
       auto rgA = data.Shower(gnodeA);
       auto rgB = data.Shower(gnodeB);
       auto angle = rgA.Dir().Angle(rgB.Dir());

       std::cout<<"Energy A "<<rgA._energy/2.<<" Energy B"<<rgB._energy/2.<<" Angle Between Showers"<<angle<<std::endl;
       std::cout<<"Mass "<< sqrt(2.*rgA._energy/2.*rgB._energy/2.*(1-cos(angle)))<<"\n\n"<<std::endl;













return true; }

  void ERAnaEventByEvent::ProcessEnd(TFile* fout)
  {}

}

#endif
