#include "MomentumBalanceKernel.h"


registerMooseObject("nyauliApp", MomentumBalanceKernel);


InputParameters
MomentumBalanceKernel::validParams()
{
  auto params = ADKernel::validParams();
  params.addClassDescription("Solve the linear momentum balance equation");
  params.addParam<MaterialPropertyName>("stress", "stress", "The stress to balance");
  params.addRequiredParam<unsigned int>("component", "The residual component");
  return params;
}

MomentumBalanceKernel::MomentumBalanceKernel(const InputParameters & params)
  : ADKernel(params),
    _s(getADMaterialProperty<RankTwoTensor>("stress")),
    _component(getParam<unsigned int>("component"))
{
}


ADReal
MomentumBalanceKernel::computeQpResidual()
{
  return _grad_test[_i][_qp] * _s[_qp].row(_component);
}

