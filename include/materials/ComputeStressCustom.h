#pragma once

#include "Material.h"
#include "RankTwoTensor.h"

class ComputeStressCustom : public Material
{
public:
  static InputParameters validParams();

  ComputeStressCustom(const InputParameters &);

protected:
  // REMOVE_BEGIN
  virtual void computeQpProperties() override;
  // REMOVE_END

  const ADMaterialProperty<RankTwoTensor> & _e;

  const ADMaterialProperty<Real> & _E;

  const ADMaterialProperty<Real> & _nu;

  ADMaterialProperty<RankTwoTensor> & _s;
};
