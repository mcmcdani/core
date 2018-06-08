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

#include <biogears/cdm/properties/SEScalarAreaPerTimePressure.h>
#include <biogears/cdm/stdafx.h>

const AreaPerTimePressureUnit AreaPerTimePressureUnit::m2_Per_s_mmHg("m^2/s mmHg");
const AreaPerTimePressureUnit AreaPerTimePressureUnit::cm2_Per_s_mmHg("cm^2/s mmHg");
const AreaPerTimePressureUnit AreaPerTimePressureUnit::m2_Per_min_mmHg("m^2/min mmHg");
const AreaPerTimePressureUnit AreaPerTimePressureUnit::cm2_Per_min_mmHg("cm^2/min mmHg");

CDM::ScalarAreaPerTimePressureData* SEScalarAreaPerTimePressure::Unload() const
{
  if (!IsValid())
    return nullptr;
  CDM::ScalarAreaPerTimePressureData* data(new CDM::ScalarAreaPerTimePressureData());
  SEScalarQuantity::Unload(*data);
  return data;
}

bool AreaPerTimePressureUnit::IsValidUnit(const std::string& unit)
{
  if (m2_Per_s_mmHg.GetString().compare(unit) == 0)
    return true;
  if (cm2_Per_s_mmHg.GetString().compare(unit) == 0)
    return true;
  if (m2_Per_min_mmHg.GetString().compare(unit) == 0)
    return true;
  if (cm2_Per_min_mmHg.GetString().compare(unit) == 0)
    return true;
  return false;
}

const AreaPerTimePressureUnit& AreaPerTimePressureUnit::GetCompoundUnit(const std::string& unit)
{
  if (m2_Per_s_mmHg.GetString().compare(unit) == 0)
    return m2_Per_s_mmHg;
  if (cm2_Per_s_mmHg.GetString().compare(unit) == 0)
    return cm2_Per_s_mmHg;
  if (m2_Per_min_mmHg.GetString().compare(unit) == 0)
    return m2_Per_min_mmHg;
  if (cm2_Per_min_mmHg.GetString().compare(unit) == 0)
    return cm2_Per_min_mmHg;
  std::stringstream err;
  err << unit << " is not a valid AreaPerTimePressure unit";
  throw CommonDataModelException(err.str());
}