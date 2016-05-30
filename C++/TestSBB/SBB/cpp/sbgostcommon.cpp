#include "sbgostcommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELGOSTBASE

SB_INLINE void TElGOSTBase::Init(const TElGostSubstBlock &SubstBlock)
{
	SBCheckError(TElGOSTBase_Init(_Handle, &SubstBlock));
}

SB_INLINE void TElGOSTBase::Reset()
{
	SBCheckError(TElGOSTBase_Reset(_Handle));
}

SB_INLINE void TElGOSTBase::Clone(TElGOSTBase &Source)
{
	SBCheckError(TElGOSTBase_Clone(_Handle, Source.getHandle()));
}

SB_INLINE void TElGOSTBase::Clone(TElGOSTBase *Source)
{
	SBCheckError(TElGOSTBase_Clone(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElGOSTBase::EncryptBlock(uint32_t &B0, uint32_t &B1)
{
	SBCheckError(TElGOSTBase_EncryptBlock(_Handle, &B0, &B1));
}

SB_INLINE void TElGOSTBase::DecryptBlock(uint32_t &B0, uint32_t &B1)
{
	SBCheckError(TElGOSTBase_DecryptBlock(_Handle, &B0, &B1));
}

SB_INLINE void TElGOSTBase::MakeSubstBlock(const std::string &GostSubstBlockHex, TElGostSubstBlock &OutResult)
{
	SBCheckError(TElGOSTBase_MakeSubstBlock(GostSubstBlockHex.data(), (int32_t)GostSubstBlockHex.length(), &OutResult));
}

SB_INLINE void TElGOSTBase::MakeSubstBlock_Inst(const std::string &GostSubstBlockHex, TElGostSubstBlock &OutResult)
{
	SBCheckError(TElGOSTBase_MakeSubstBlock_1(_Handle, GostSubstBlockHex.data(), (int32_t)GostSubstBlockHex.length(), &OutResult));
}

TElGOSTBase::TElGOSTBase(TElGOSTBaseHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElGOSTBase::TElGOSTBase() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOSTBase_Create(&_Handle));
}

TElGOSTBase::TElGOSTBase(const TElGostSubstBlock &SubstBlock) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElGOSTBase_Create_1(&SubstBlock, &_Handle));
}

#endif /* SB_USE_CLASS_TELGOSTBASE */

};	/* namespace SecureBlackbox */

