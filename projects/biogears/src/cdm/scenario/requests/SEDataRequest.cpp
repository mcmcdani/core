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

#include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <biogears/cdm/scenario/requests/SEEnvironmentDataRequest.h>
#include <biogears/cdm/scenario/requests/SEEquipmentDataRequest.h>
#include <biogears/cdm/scenario/requests/SEPatientDataRequest.h>
#include <biogears/cdm/scenario/requests/SEPhysiologyDataRequest.h>
#include <biogears/cdm/scenario/requests/SESubstanceDataRequest.h>
#include <biogears/cdm/stdafx.h>
#include <biogears/schema/DataRequestData.hxx>
#include <biogears/schema/EnvironmentDataRequestData.hxx>
#include <biogears/schema/EquipmentDataRequestData.hxx>
#include <biogears/schema/PatientDataRequestData.hxx>
#include <biogears/schema/PhysiologyDataRequestData.hxx>
#include <biogears/schema/SubstanceDataRequestData.hxx>

#include <biogears/cdm/scenario/requests/SEGasCompartmentDataRequest.h>
#include <biogears/cdm/scenario/requests/SELiquidCompartmentDataRequest.h>
#include <biogears/cdm/scenario/requests/SEThermalCompartmentDataRequest.h>
#include <biogears/cdm/scenario/requests/SETissueCompartmentDataRequest.h>
#include <biogears/schema/GasCompartmentDataRequestData.hxx>
#include <biogears/schema/LiquidCompartmentDataRequestData.hxx>
#include <biogears/schema/ThermalCompartmentDataRequestData.hxx>
#include <biogears/schema/TissueCompartmentDataRequestData.hxx>

#include <biogears/cdm/properties/SEScalar.h>
#include <biogears/cdm/substance/SESubstanceManager.h>

SEDataRequest::SEDataRequest(const SEDecimalFormat* dfault)
  : SEDecimalFormat(dfault)
{
  m_Name = "";
  m_RequestedUnit = "";
  m_Unit = nullptr;
}

SEDataRequest::~SEDataRequest()
{
  Clear();
}

void SEDataRequest::Clear()
{
  m_Name = "";
  m_RequestedUnit = "";
  m_Unit = nullptr;
}

size_t SEDataRequest::HashCode() const
{
  size_t h = std::hash<std::string>()(m_Name);
  return h;
}

bool SEDataRequest::Load(const CDM::DataRequestData& in)
{
  SEDecimalFormat::Load(in);
  m_Name = in.Name();
  if (in.Unit().present())
    m_RequestedUnit = in.Unit().get();
  return true;
}

CDM::DataRequestData* SEDataRequest::Unload() const
{
  CDM::DataRequestData* data = new CDM::DataRequestData();
  Unload(*data);
  return data;
}

void SEDataRequest::Unload(CDM::DataRequestData& data) const
{
  SEDecimalFormat::Unload(data);
  data.Name(m_Name);
  if (HasUnit())
    data.Unit(m_Unit->GetString());
  else if (HasRequestedUnit())
    data.Unit(m_RequestedUnit);
}

std::string SEDataRequest::GetName() const
{
  return m_Name;
}
void SEDataRequest::SetName(const std::string& name)
{
  m_Name = name;
}
bool SEDataRequest::HasName() const
{
  return m_Name.empty() ? false : true;
}
void SEDataRequest::InvalidateName()
{
  m_Name = "";
}

std::string SEDataRequest::GetRequestedUnit() const
{
  return m_RequestedUnit;
}
void SEDataRequest::SetRequestedUnit(const std::string& unit)
{
  m_RequestedUnit = unit;
  m_Unit = nullptr;
}
bool SEDataRequest::HasRequestedUnit() const
{
  return m_RequestedUnit.empty() ? false : true;
}
void SEDataRequest::InvalidateRequestedUnit()
{
  m_RequestedUnit = "";
}

const CCompoundUnit* SEDataRequest::GetUnit() const
{
  return m_Unit;
}
void SEDataRequest::SetUnit(const CCompoundUnit& unit)
{
  m_Unit = &unit;
  m_RequestedUnit = "";
}
bool SEDataRequest::HasUnit() const
{
  return m_Unit == nullptr ? false : true;
}
void SEDataRequest::InvalidateUnit()
{
  m_Unit = nullptr;
}

void SEDataRequest::Set(const std::string& name, const std::string& unit)
{
  m_Name = name;
  m_RequestedUnit = unit;
  m_Unit = nullptr;
}

void SEDataRequest::Set(const std::string& name, const CCompoundUnit& unit)
{
  m_Name = name;
  m_RequestedUnit = "";
  m_Unit = &unit;
}
