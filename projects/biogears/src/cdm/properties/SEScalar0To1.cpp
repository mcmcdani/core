/**************************************************************************************
Copyright 2015 Applied Research Associates, Inc.
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the License
at:
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under
the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
**************************************************************************************/

#include <biogears/cdm/properties/SEScalar0To1.h>
#include <biogears/cdm/stdafx.h>
#include <biogears/schema/Properties.hxx>

SEScalar0To1::SEScalar0To1()
  : SEScalar()
{
}

CDM::Scalar0To1Data* SEScalar0To1::Unload() const
{
  if (!IsValid())
    return nullptr;
  CDM::Scalar0To1Data* data(new CDM::Scalar0To1Data());
  SEScalar::Unload(*data);
  return data;
}

void SEScalar0To1::SetValue(double d)
{
  if (d > 1 || d < 0)
    throw CommonDataModelException("SEScalar0To1 must be between [0,1]");
  SEScalar::SetValue(d);
}

void SEScalar0To1::SetValue(double d, const NoUnit& unitless)
{
  SEScalar0To1::SetValue(d);
}
