//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "nyauliTestApp.h"
#include "nyauliApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
nyauliTestApp::validParams()
{
  InputParameters params = nyauliApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

nyauliTestApp::nyauliTestApp(InputParameters parameters) : MooseApp(parameters)
{
  nyauliTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

nyauliTestApp::~nyauliTestApp() {}

void
nyauliTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  nyauliApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"nyauliTestApp"});
    Registry::registerActionsTo(af, {"nyauliTestApp"});
  }
}

void
nyauliTestApp::registerApps()
{
  registerApp(nyauliApp);
  registerApp(nyauliTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
nyauliTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  nyauliTestApp::registerAll(f, af, s);
}
extern "C" void
nyauliTestApp__registerApps()
{
  nyauliTestApp::registerApps();
}
