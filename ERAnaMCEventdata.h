/**
 * \file ERAnaMCEventdata.h
 *
 * \ingroup Goldenpi0ana
 * 
 * \brief Class def header for a class ERAnaMCEventdata
 *
 * @author ryan
 */

/** \addtogroup Goldenpi0ana

    @{*/

#ifndef ERTOOL_ERANAMCEVENTDATA_H
#define ERTOOL_ERANAMCEVENTDATA_H

#include "ERTool/Base/AnaBase.h"

namespace ertool {

  /**
     \class ERAnaMCEventdata
     User custom Analysis class made by kazuhiro
   */
  class ERAnaMCEventdata : public AnaBase {
  
  public:

    /// Default constructor
    ERAnaMCEventdata(const std::string& name="ERAnaMCEventdata");

    /// Default destructor
    virtual ~ERAnaMCEventdata(){}

    /// Reset function
    virtual void Reset();

    /// Function to accept fclite::PSet
    void AcceptPSet(const ::fcllite::PSet& cfg);

    /// Called @ before processing the first event sample
    void ProcessBegin();

    /// Function to evaluate input showers and determine a score
    bool Analyze(const EventData &data, const ParticleGraph &graph);

    /// Called after processing the last event sample
    void ProcessEnd(TFile* fout=nullptr);

  };
}
#endif

/** @} */ // end of doxygen group 
