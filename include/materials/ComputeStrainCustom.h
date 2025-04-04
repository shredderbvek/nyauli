#pragma once

#include "Material.h"
#include "RankTwoTensor.h"

class ComputeStrainCustom : public Material
{
public:
  static InputParameters validParams();

  ComputeStrainCustom(const InputParameters &);

protected:
  virtual void computeQpProperties() override;

  std::vector<const ADVariableGradient *> _grad_u;

  ADMaterialProperty<RankTwoTensor> & _e;
};
