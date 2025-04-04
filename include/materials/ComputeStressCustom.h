#pragma once

#include "Material.h"
#include "RankTwoTensor.h"

class ComputeStressCustom : public Material
{
public:
  static InputParameters validParams();

  ComputeStressCustom(const InputParameters &);

protected:
 
  virtual void computeQpProperties() override;

  const ADMaterialProperty<RankTwoTensor> & _e;

  const ADMaterialProperty<Real> & _E;

  const ADMaterialProperty<Real> & _nu;

  ADMaterialProperty<RankTwoTensor> & _s;
};
