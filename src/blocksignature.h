// Copyright (c) 2015-2017 The PIVX developers// Copyright (c) 2017-2020 The Adeptio developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ADE_BLOCKSIGNATURE_H
#define ADE_BLOCKSIGNATURE_H

#include "key.h"
#include "primitives/block.h"
#include "keystore.h"

bool SignBlockWithKey(CBlock& block, const CKey& key);
bool SignBlock(CBlock& block, const CKeyStore& keystore);
bool CheckBlockSignature(const CBlock& block);

#endif //ADE_BLOCKSIGNATURE_H
