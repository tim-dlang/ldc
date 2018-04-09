//===-- bind.h - jit support ------------------------------------*- C++ -*-===//
//
//                         LDC – the LLVM D compiler
//
// This file is distributed under the Boost Software License. See the LICENSE
// file for details.
//
//===----------------------------------------------------------------------===//
//
// Jit runtime - support routines for bind, allow to dynamically create
// specialized functions for each bind instance.
//
//===----------------------------------------------------------------------===//

#ifndef BIND_H
#define BIND_H

#include "context.h" // Slice

#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/STLExtras.h"

namespace llvm {
class Module;
class Function;
}

llvm::Function *bindParamsToFunc(
    llvm::Module &module, llvm::Function &srcFunc,
    const llvm::ArrayRef<Slice> &params,
    llvm::function_ref<void(const std::string &)> errHandler);

#endif // BIND_H
