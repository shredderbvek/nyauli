#include "ComputeStrainCustom.h"


registerMooseObject("nyauliApp", ComputeStrainCustom);


InputParameters
ComputeStrainCustom::validParams()
{
  auto params = Material::validParams();
  params.addClassDescription("Calculate strain as function of displacement gradients");
  params.addRequiredCoupledVar("displacements", "Displacement variables");
  params.addParam<MaterialPropertyName>("strain", "strain", "Name of the strain");
  return params;
}

ComputeStrainCustom::ComputeStrainCustom(const InputParameters & params)
  : Material(params),
    _grad_u(adCoupledGradients("displacements")),
    _e(declareADProperty<RankTwoTensor>("strain"))
{
  _grad_u.resize(3, &_ad_grad_zero);
}


void
ComputeStrainCustom::computeQpProperties()
{
  using R2 = ADRankTwoTensor;

  auto G = R2::initializeFromRows((*_grad_u[0])[_qp], (*_grad_u[1])[_qp], (*_grad_u[2])[_qp]);
  _e[_qp] = (G.transpose() + G) / 2;
}

