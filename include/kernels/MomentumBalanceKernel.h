#pragma once

#include "ADKernel.h"
#include "RankTwoTensor.h"

class MomentumBalanceKernel : public ADKernel
{
public:
  static InputParameters validParams();

  MomentumBalanceKernel(const InputParameters &);

protected:
  virtual ADReal computeQpResidual() override;


  const ADMaterialProperty<RankTwoTensor> & _s;

  const unsigned int _component;
};
