#include "nyauliApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
nyauliApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

nyauliApp::nyauliApp(InputParameters parameters) : MooseApp(parameters)
{
  nyauliApp::registerAll(_factory, _action_factory, _syntax);
}

nyauliApp::~nyauliApp() {}

void
nyauliApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<nyauliApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"nyauliApp"});
  Registry::registerActionsTo(af, {"nyauliApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
nyauliApp::registerApps()
{
  registerApp(nyauliApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
nyauliApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  nyauliApp::registerAll(f, af, s);
}
extern "C" void
nyauliApp__registerApps()
{
  nyauliApp::registerApps();
}
