#include <iostream>
#include <itkLBFGSBOptimizer.h>
#include "DebugSlicerCLICLP.h"
int main(int , char * [])
{
//  PARSE_ARGS;
  typedef itk::LBFGSBOptimizer                    LBFGSBOptimizerType;
  typedef LBFGSBOptimizerType::Pointer            LBFGSBOptimizerTypePointer;
  typedef LBFGSBOptimizerType::ParametersType     OptimizerParameterType;
  typedef LBFGSBOptimizerType::ScalesType         OptimizerScalesType;
  typedef LBFGSBOptimizerType::BoundSelectionType OptimizerBoundSelectionType;
  typedef LBFGSBOptimizerType::BoundValueType     OptimizerBoundValueType;

  std::cout << "TESTING: STARTED" << std::endl;
  LBFGSBOptimizerTypePointer LBFGSBoptimizer = LBFGSBOptimizerType::New();
    {
    OptimizerBoundValueType upperBound( 9945 );
    upperBound.Fill(12345);
    std::cout << "PRE : " << upperBound.size() << " " << std::flush;
    std::cout << LBFGSBoptimizer->GetUpperBound().size() << std::endl;
    LBFGSBoptimizer->SetUpperBound(upperBound);
    const OptimizerBoundValueType & tempUB=LBFGSBoptimizer->GetUpperBound();
    std::cout << "POST: " << upperBound.size() << " " << std::flush;
    std::cout << tempUB.size() << std::endl;
    }
    {
    OptimizerBoundValueType lowerBound( 9945 );
    lowerBound.Fill(-12345);

    std::cout << "PRE : " << lowerBound.size() << " " << std::flush;
    std::cout << LBFGSBoptimizer->GetLowerBound().size() << std::endl;
    LBFGSBoptimizer->SetLowerBound(lowerBound);
    const OptimizerBoundValueType & tempLB=LBFGSBoptimizer->GetLowerBound();
    std::cout << "POST: " << lowerBound.size() << " " << std::flush;
    std::cout << tempLB.size() << std::endl;
    }
  std::cout << "TESTING: STOPPED" << std::endl;
  return 0;
}
