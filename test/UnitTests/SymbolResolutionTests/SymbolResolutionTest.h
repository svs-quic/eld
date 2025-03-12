//===- SymbolResolutionTest.h ----------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef UNITTESTS_SYMBOL_RESOLUTION_TEST_H
#define UNITTESTS_SYMBOL_RESOLUTION_TEST_H

#include <gtest/gtest.h>

namespace eld {
class DiagnosticEngine;
class IRBuilder;
class LinkerConfig;
class Module;
} // namespace eld

/** \class SymbolResolutionTest
 *  \brief The testcases for symbol resolution
 *
 */
class SymbolResolutionTest : public ::testing::Test {
public:
  // Constructor can do set-up work for all test here.
  SymbolResolutionTest();

  // Destructor can do clean-up work that doesn't throw exceptions here.
  virtual ~SymbolResolutionTest() override;

  // SetUp() will be called immediately before each test.
  virtual void SetUp() override;

  // TearDown() will be called immediately after each test.
  virtual void TearDown() override;

protected:
  eld::DiagnosticEngine *m_DiagEngine = nullptr;
  eld::IRBuilder *m_IRBuilder = nullptr;
  eld::LinkerConfig *m_Config = nullptr;
  eld::Module *m_Module = nullptr;
};

#endif
