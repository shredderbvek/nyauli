[GlobalParams]
  displacements = 'disp_x disp_y disp_z'
[]
[Variables]
  [disp_x]
  []
  [disp_y]
  []
  [disp_z]
  []
[]

[Mesh]
    file = beam1.e
[]

[Kernels]
  [momentum_balance_x]
    type = MomentumBalanceKernel
    variable = disp_x
    component = 0
  []
  [momentum_balance_y]
    type = MomentumBalanceKernel
    variable = disp_y
    component = 1
  []
  [momentum_balance_z]
    type = MomentumBalanceKernel
    variable = disp_z
    component = 2
  []
[]

[Materials]
  [strain]
    type = ComputeStrainCustom
  []
  [stress]
    type = ComputeStressCustom
    youngs_modulus = 2.1e5
    poissons_ratio = 0.3
  []
[]

[BCs]
    [fix_x]
        type = DirichletBC
        variable = disp_x
        value = 0
        boundary = "fixed_face"
    []
    [fix_y]
        type = DirichletBC
        variable = disp_y
        value = 0
        boundary = "fixed_face"
    []
    [fix_z]
        type = DirichletBC
        variable = disp_z
        value = 0
        boundary = "fixed_face"
    []
    [pressure_top]
        type = Pressure
        variable = disp_y
        boundary = "load_face"
        function = 0.5*t
    []
[]

[Executioner]
    type = Transient
    solve_type = NEWTON
    end_time = 1
    dt = 0.2
[]

[Outputs]
    exodus = true
[]
