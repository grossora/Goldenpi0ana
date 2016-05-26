/**
 * \file ERAnaEventByEvent.h
 *
 * \ingroup Goldenpi0ana
 * 
 * \brief Class def header for a class ERAnaEventByEvent
 *
 * @author ryan
 */

/** \addtogroup Goldenpi0ana

    @{*/

#ifndef ERTOOL_ERANAEVENTBYEVENT_H
#define ERTOOL_ERANAEVENTBYEVENT_H

#include "ERTool/Base/AnaBase.h"
#include "ERTool/Base/ParticleGraph.h"
#include "ERTool/Base/Particle.h"
#include "ERTool/Base/EventData.h"


namespace ertool {

  /**
     \class ERAnaEventByEvent
     User custom Analysis class made by kazuhiro
   */
  class ERAnaEventByEvent : public AnaBase {
  
  public:

    /// Default constructor
    ERAnaEventByEvent(const std::string& name="ERAnaEventByEvent");

    /// Default destructor
    virtual ~ERAnaEventByEvent(){}

    /// Reset function
    virtual void Reset();

    /// Function to accept fclite::PSet
    void AcceptPSet(const ::fcllite::PSet& cfg);

    /// Called @ before processing the first event sample
    void ProcessBegin();

    /// Function to evaluate input showers and determine a score
    bool Analyze(const EventData &data, const ParticleGraph &ps);

    /// Called after processing the last event sample
    void ProcessEnd(TFile* fout=nullptr);

  };
}
#endif

/** @} */ // end of doxygen group 
