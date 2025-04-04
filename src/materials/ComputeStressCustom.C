#include "ComputeStressCustom.h"


registerMooseObject("nyauliApp", ComputeStressCustom);


InputParameters
ComputeStressCustom::validParams()
{
  auto params = Material::validParams();
  params.addClassDescription("Calculate stress for a linear elastic material");
  params.addRequiredParam<MaterialPropertyName>("youngs_modulus", "young's modulus of elasticity of a linear isotropic material");
  params.addRequiredParam<MaterialPropertyName>("poissons_ratio", "poissons ratio of a linear isotropic material");
  params.addParam<MaterialPropertyName>("strain", "strain", "Name of the strain");
  params.addParam<MaterialPropertyName>("stress", "stress", "Name of the stress");
  return params;
}

ComputeStressCustom::ComputeStressCustom(const InputParameters & params)
  : Material(params),
    _e(getADMaterialProperty<RankTwoTensor>("strain")),
    _E(getADMaterialProperty<Real>("youngs_modulus")),
    _nu(getADMaterialProperty<Real>("poissons_ratio")),
    _s(declareADProperty<RankTwoTensor>("stress"))
{
}

void
ComputeStressCustom::computeQpProperties()
{
  using R2 = ADRankTwoTensor;

  _s[_qp] = _E[_qp]*_nu[_qp]/((1-2*_nu[_qp])*(1+_nu[_qp])) * _e[_qp].trace() * R2::Identity() + _E[_qp]/(1+_nu[_qp]) * _e[_qp];
}
