/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2016, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#include "WeibullDistribution.hpp"
#include "UncertaintyDescription_Impl.hpp"

#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace analysis {

WeibullDistribution::WeibullDistribution() 
  : UncertaintyDescription(std::shared_ptr<detail::UncertaintyDescription_Impl>(
        new detail::UncertaintyDescription_Impl(WeibullDistribution::type())))
{}

WeibullDistribution::WeibullDistribution(double alpha, double beta) 
  : UncertaintyDescription(std::shared_ptr<detail::UncertaintyDescription_Impl>(
        new detail::UncertaintyDescription_Impl(WeibullDistribution::type())))
{
  setAlpha(alpha);
  setBeta(beta);
}

UncertaintyDescriptionType WeibullDistribution::type() {
  return UncertaintyDescriptionType(UncertaintyDescriptionType::weibull_uncertain);
}

double WeibullDistribution::alpha() const {
  return impl()->getAttribute("alphas",false).valueAsDouble();
}

double WeibullDistribution::beta() const {
  return impl()->getAttribute("betas",false).valueAsDouble();
}

bool WeibullDistribution::setAlpha(double value) {
  if (value > 0) {
    impl()->setAttribute(Attribute("alphas",value),false);
    return true;
  }
  else {
    LOG(Warn,"The alphas of a weibull distribution must be positive.");
    return false;
  }
}

bool WeibullDistribution::setBeta(double value) {
  if (value > 0) {
    impl()->setAttribute(Attribute("betas",value),false);
    return true;
  }
  else {
    LOG(Warn,"The betas of a weibull distribution must be positive.");
    return false;
  }  
}

WeibullDistribution::WeibullDistribution(std::shared_ptr<detail::UncertaintyDescription_Impl> impl)
  : UncertaintyDescription(impl)
{
  OS_ASSERT(type() == WeibullDistribution::type());
}

} // analysis
} // openstudio