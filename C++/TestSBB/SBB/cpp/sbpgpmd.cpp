#include "sbpgpmd.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL

SB_INLINE int32_t TElPGPHashingPool::Add(int32_t Algorithm, bool SkipIfExists)
{
	int32_t OutResult;
	SBCheckError(TElPGPHashingPool_Add(_Handle, Algorithm, (int8_t)SkipIfExists, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPHashingPool::Clear()
{
	SBCheckError(TElPGPHashingPool_Clear(_Handle));
}

SB_INLINE void TElPGPHashingPool::Remove(int32_t Index)
{
	SBCheckError(TElPGPHashingPool_Remove(_Handle, Index));
}

SB_INLINE void TElPGPHashingPool::Reset()
{
	SBCheckError(TElPGPHashingPool_Reset(_Handle));
}

SB_INLINE void TElPGPHashingPool::NFinalize()
{
	SBCheckError(TElPGPHashingPool_NFinalize(_Handle));
}

SB_INLINE void TElPGPHashingPool::Update(void * Buffer, int32_t Size)
{
	SBCheckError(TElPGPHashingPool_Update(_Handle, Buffer, Size));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPHashingPool::Update(TStream &Stream, int32_t Count)
{
	SBCheckError(TElPGPHashingPool_Update_1(_Handle, Stream.getHandle(), Count));
}

SB_INLINE void TElPGPHashingPool::Update(TStream *Stream, int32_t Count)
{
	SBCheckError(TElPGPHashingPool_Update_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElPGPHashingPool::GetContextByAlgorithm(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(TElPGPHashingPool_GetContextByAlgorithm(_Handle, Algorithm, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHASHFUNCTION
TElHashFunction* TElPGPHashingPool::get_HashFunctions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPHashingPool_get_HashFunctions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HashFunctions)
		this->_Inst_HashFunctions = new TElHashFunction(hOutResult, ohFalse);
	else
		this->_Inst_HashFunctions->updateHandle(hOutResult);
	return this->_Inst_HashFunctions;
}
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

SB_INLINE int32_t TElPGPHashingPool::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPGPHashingPool_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPHashingPool::get_DataIsText()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPHashingPool_get_DataIsText(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPHashingPool::set_DataIsText(bool Value)
{
	SBCheckError(TElPGPHashingPool_set_DataIsText(_Handle, (int8_t)Value));
}

bool TElPGPHashingPool::get_CompMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPHashingPool_get_CompMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPHashingPool::set_CompMode(bool Value)
{
	SBCheckError(TElPGPHashingPool_set_CompMode(_Handle, (int8_t)Value));
}

void TElPGPHashingPool::initInstances()
{
#ifdef SB_USE_CLASS_TELHASHFUNCTION
	this->_Inst_HashFunctions = NULL;
#endif /* SB_USE_CLASS_TELHASHFUNCTION */
}

TElPGPHashingPool::TElPGPHashingPool(TElPGPHashingPoolHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElPGPHashingPool::TElPGPHashingPool() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPHashingPool_Create(&_Handle));
}

TElPGPHashingPool::~TElPGPHashingPool()
{
#ifdef SB_USE_CLASS_TELHASHFUNCTION
	delete this->_Inst_HashFunctions;
	this->_Inst_HashFunctions = NULL;
#endif /* SB_USE_CLASS_TELHASHFUNCTION */
}
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

#ifdef SB_USE_GLOBAL_PROCS_PGPMD

SB_INLINE int32_t MDGetDigestSize(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPMD_MDGetDigestSize(Algorithm, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELHASHFUNCTION
void MDInitialize(TElHashFunction &HashFunction, int32_t Algorithm)
{
	TElClassHandle hHashFunction = HashFunction.getHandle();
	SBCheckError(SBPGPMD_MDInitialize(&hHashFunction, Algorithm));
	HashFunction.updateHandle(hHashFunction);
}
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

void MDHash(int32_t Algorithm, const std::vector<uint8_t> &Data, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPMD_MDHash(Algorithm, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1177040499, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELHASHFUNCTION
void MDFinalize(TElHashFunction &HashFunction, std::vector<uint8_t> &OutResult)
{
	TElClassHandle hHashFunction = HashFunction.getHandle();
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPMD_MDFinalize(&hHashFunction, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-982378395, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	HashFunction.updateHandle(hHashFunction);
	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#endif /* SB_USE_GLOBAL_PROCS_PGPMD */

};	/* namespace SecureBlackbox */

