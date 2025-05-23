//===- StrToken.h----------------------------------------------------------===//
// Part of the eld Project, under the BSD License
// See https://github.com/qualcomm/eld/LICENSE.txt for license information.
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ELD_SCRIPT_STRTOKEN_H
#define ELD_SCRIPT_STRTOKEN_H

#include <string>

namespace eld {

/** \class StrToken
 *  \brief This class defines the interfaces to a element in EXCLUDE_FILE list
 *         or in Output Section Phdr, or be a base class of other str token.
 */

class StrToken {
public:
  enum Kind { Unknown, String, Input, Wildcard };

  explicit StrToken(const std::string &PString, Kind K = StrToken::String);

  virtual ~StrToken() {}

  Kind kind() const { return ScriptFileKind; }

  const std::string &name() const { return Name; }

  static bool classof(const StrToken *ThisInputToken) {
    return ThisInputToken->kind() == StrToken::String;
  }

  bool isQuoted() const { return Quoted; }

  void setQuoted() { Quoted = true; }

  std::string getDecoratedName() const;

protected:
  std::string Name;
  bool Quoted = false;
  Kind ScriptFileKind;
};

} // namespace eld

#endif
