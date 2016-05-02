/**
 * \file ERAnaCutFileter.h
 *
 * \ingroup Goldenpi0ana
 * 
 * \brief Class def header for a class ERAnaCutFileter
 *
 * @author ryan
 */

/** \addtogroup Goldenpi0ana

    @{*/

#ifndef ERTOOL_ERANACUTFILETER_H
#define ERTOOL_ERANACUTFILETER_H

#include "ERTool/Base/AnaBase.h"

namespace ertool {

  /**
     \class ERAnaCutFileter
     User custom Analysis class made by kazuhiro
   */
  class ERAnaCutFileter : public AnaBase {
  
  public:

    /// Default constructor
    ERAnaCutFileter(const std::string& name="ERAnaCutFileter");

    /// Default destructor
    virtual ~ERAnaCutFileter(){}

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

	private: 
	double _MinMass = 0 ; 
	double _MaxMass = 10000000 ; 

  };
}
#endif

/** @} */ // end of doxygen group 
