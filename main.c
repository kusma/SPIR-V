#include <stdint.h>
#include <stdlib.h>

struct sv_instr {
	uint16_t word_count;
	uint16_t opcode;
	uint32_t *operands;
};

struct sv_module {
	uint32_t magic;
	uint32_t version;
	uint32_t generator;
	uint32_t bound;
	uint32_t reserved;

	struct sv_instr *instrs;
	int num_instrs;
};

#define SV_MAGIC 0x07230203

enum sv_opcode {
	OpNop = 0,
	OpSource = 1,
	OpSourceExtension = 2,
	OpExtension = 3,
	OpExtInstImport = 4,
	OpMemoryModel = 5,
	OpEntryPoint = 6,
	OpExecutionMode = 7,
	OpTypeVoid = 8,
	OpTypeBool = 9,
	OpTypeInt = 10,
	OpTypeFloat = 11,
	OpTypeVector = 12,
	OpTypeMatrix = 13,
	OpTypeSampler = 14,
	OpTypeFilter = 15,
	OpTypeArray = 16,
	OpTypeRuntimeArray = 17,
	OpTypeStruct = 18,
	OpTypeOpaque = 19,
	OpTypePointer = 20,
	OpTypeFunction = 21,
	OpTypeEvent = 22,
	OpTypeDeviceEvent = 23,
	OpTypeReserveId = 24,
	OpTypeQueue = 25,
	OpTypePipe = 26,
	OpConstantTrue = 27,
	OpConstantFalse = 28,
	OpConstant = 29,
	OpConstantComposite = 30,
	OpConstantSampler = 31,
	OpConstantNullPointer = 32,
	OpConstantNullObject = 33,
	OpSpecConstantTrue = 34,
	OpSpecConstantFalse = 35,
	OpSpecConstant = 36,
	OpSpecConstantComposite = 37,
	OpVariable = 38,
	OpVariableArray = 39,
	OpFunction = 40,
	OpFunctionParameter = 41,
	OpFunctionEnd = 42,
	OpFunctionCall = 43,
	OpExtInst = 44,
	OpUndef = 45,
	OpLoad = 46,
	OpStore = 47,
	OpPhi = 48,
	OpDecorationGroup = 49,
	OpDecorate = 50,
	OpMemberDecorate = 51,
	OpGroupDecorate = 52,
	OpGroupMemberDecorate = 53,
	OpName = 54,
	OpMemberName = 55,
	OpString = 56,
	OpLine = 57,
	OpVectorExtractDynamic = 58,
	OpVectorInsertDynamic = 59,
	OpVectorShuffle = 60,
	OpCompositeConstruct = 61,
	OpCompositeExtract = 62,
	OpCompositeInsert = 63,
	OpCopyObject = 64,
	OpCopyMemory = 65,
	OpCopyMemorySized = 66,
	OpSampler = 67,
	OpTextureSample = 68,
	OpTextureSampleDref = 69,
	OpTextureSampleLod = 70,
	OpTextureSampleProj = 71,
	OpTextureSampleGrad = 72,
	OpTextureSampleOffset = 73,
	OpTextureSampleProjLod = 74,
	OpTextureSampleProjGrad = 75,
	OpTextureSampleLodOffset = 76,
	OpTextureSampleProjOffset = 77,
	OpTextureSampleGradOffset = 78,
	OpTextureSampleProjLodOffset = 79,
	OpTextureSampleProjGradOffset = 80,
	OpTextureFetchTexel = 81,
	OpTextureFetchTexelOffset = 82,
	OpTextureFetchSample = 83,
	OpTextureFetchBuffer = 84,
	OpTextureGather = 85,
	OpTextureGatherOffset = 86,
	OpTextureGatherOffsets = 87,
	OpTextureQuerySizeLod = 88,
	OpTextureQuerySize = 89,
	OpTextureQueryLod = 90,
	OpTextureQueryLevels = 91,
	OpTextureQuerySamples = 92,
	OpAccessChain = 93,
	OpInBoundsAccessChain = 94,
	OpSNegate = 95,
	OpFNegate = 96,
	OpNot = 97,
	OpAny = 98,
	OpAll = 99,
	OpConvertFToU = 100,
	OpConvertFToS = 101,
	OpConvertSToF = 102,
	OpConvertUToF = 103,
	OpUConvert = 104,
	OpSConvert = 105,
	OpFConvert = 106,
	OpConvertPtrToU = 107,
	OpConvertUToPtr = 108,
	OpPtrCastToGeneric = 109,
	OpGenericCastToPtr = 110,
	OpBitcast = 111,
	OpTranspose = 112,
	OpIsNan = 113,
	OpIsInf = 114,
	OpIsFinite = 115,
	OpIsNormal = 116,
	OpSignBitSet = 117,
	OpLessOrGreater = 118,
	OpOrdered = 119,
	OpUnordered = 120,
	OpArrayLength = 121,
	OpIAdd = 122,
	OpFAdd = 123,
	OpISub = 124,
	OpFSub = 125,
	OpIMul = 126,
	OpFMul = 127,
	OpUDiv = 128,
	OpSDiv = 129,
	OpFDiv = 130,
	OpUMod = 131,
	OpSRem = 132,
	OpSMod = 133,
	OpFRem = 134,
	OpFMod = 135,
	OpVectorTimesScalar = 136,
	OpMatrixTimesScalar = 137,
	OpVectorTimesMatrix = 138,
	OpMatrixTimesVector = 139,
	OpMatrixTimesMatrix = 140,
	OpOuterProduct = 141,
	OpDot = 142,
	OpShiftRightLogical = 143,
	OpShiftRightArithmetic = 144,
	OpShiftLeftLogical = 145,
	OpLogicalOr = 146,
	OpLogicalXor = 147,
	OpLogicalAnd = 148,
	OpBitwiseOr = 149,
	OpBitwiseXor = 150,
	OpBitwiseAnd = 151,
	OpSelect = 152,
	OpIEqual = 153,
	OpFOrdEqual = 154,
	OpFUnordEqual = 155,
	OpINotEqual = 156,
	OpFOrdNotEqual = 157,
	OpFUnordNotEqual = 158,
	OpULessThan = 159,
	OpSLessThan = 160,
	OpFOrdLessThan = 161,
	OpFUnordLessThan = 162,
	OpUGreaterThan = 163,
	OpSGreaterThan = 164,
	OpFOrdGreaterThan = 165,
	OpFUnordGreaterThan = 166,
	OpULessThanEqual = 167,
	OpSLessThanEqual = 168,
	OpFOrdLessThanEqual = 169,
	OpFUnordLessThanEqual = 170,
	OpUGreaterThanEqual = 171,
	OpSGreaterThanEqual = 172,
	OpFOrdGreaterThanEqual = 173,
	OpFUnordGreaterThanEqual = 174,
	OpDPdx = 175,
	OpDPdy = 176,
	OpFwidth = 177,
	OpDPdxFine = 178,
	OpDPdyFine = 179,
	OpFwidthFine = 180,
	OpDPdxCoarse = 181,
	OpDPdyCoarse = 182,
	OpFwidthCoarse = 183,
	OpEmitVertex = 184,
	OpEndPrimitive = 185,
	OpEmitStreamVertex = 186,
	OpEndStreamPrimitive = 187,
	OpControlBarrier = 188,
	OpMemoryBarrier = 189,
	OpImagePointer = 190,
	OpAtomicInit = 191,
	OpAtomicLoad = 192,
	OpAtomicStore = 193,
	OpAtomicExchange = 194,
	OpAtomicCompareExchange = 195,
	OpAtomicCompareExchangeWeak = 196,
	OpAtomicIIncrement = 197,
	OpAtomicIDecrement = 198,
	OpAtomicIAdd = 199,
	OpAtomicISub = 200,
	OpAtomicUMin = 201,
	OpAtomicUMax = 202,
	OpAtomicAnd = 203,
	OpAtomicOr = 204,
	OpAtomicXor = 205,
	OpLoopMerge = 206,
	OpSelectionMerge = 207,
	OpLabel = 208,
	OpBranch = 209,
	OpBranchConditional = 210,
	OpSwitch = 211,
	OpKill = 212,
	OpReturn = 213,
	OpReturnValue = 214,
	OpUnreachable = 215,
	OpLifetimeStart = 216,
	OpLifetimeStop = 217,
	OpCompileFlag = 218,
	OpAsyncGroupCopy = 219,
	OpWaitGroupEvents = 220,
	OpGroupAll = 221,
	OpGroupAny = 222,
	OpGroupBroadcast = 223,
	OpGroupIAdd = 224,
	OpGroupFAdd = 225,
	OpGroupFMin = 226,
	OpGroupUMin = 227,
	OpGroupSMin = 228,
	OpGroupFMax = 229,
	OpGroupUMax = 230,
	OpGroupSMax = 231,
	OpGenericCastToPtrExplicit = 232,
	OpGenericPtrMemSemantics = 233,
	OpReadPipe = 234,
	OpWritePipe = 235,
	OpReservedReadPipe = 236,
	OpReservedWritePipe = 237,
	OpReserveReadPipePackets = 238,
	OpReserveWritePipePackets = 239,
	OpCommitReadPipe = 240,
	OpCommitWritePipe = 241,
	OpIsValidReserveId = 242,
	OpGetNumPipePackets = 243,
	OpGetMaxPipePackets = 244,
	OpGroupReserveReadPipePackets = 245,
	OpGroupReserveWritePipePackets = 246,
	OpGroupCommitReadPipe = 247,
	OpGroupCommitWritePipe = 248,
	OpEnqueueMarker = 249,
	OpEnqueueKernel = 250,
	OpGetKernelNDrangeSubGroupCount = 251,
	OpGetKernelNDrangeMaxSubGroupSize = 252,
	OpGetKernelWorkGroupSize = 253,
	OpGetKernelPreferredWorkGroupSizeMultiple = 254,
	OpRetainEvent = 255,
	OpReleaseEvent = 256,
	OpCreateUserEvent = 257,
	OpIsValidEvent = 258,
	OpSetUserEventStatus = 259,
	OpCaptureEventProfilingInfo = 260,
	OpGetDefaultQueue = 261,
	OpBuildNDRange = 262
};


int sv_read_instr(struct sv_instr *dst, uint32_t **words, int *num_words)
{
	if (*num_words < 1)
		return -1;

	dst->word_count = **words >> 16;
	dst->opcode = **words & 0xFFFF;

	/*
         * WordCount=1 needs to be at least 1, to encode the WordCount and
	 * Opcode itself
         */
	if (dst->word_count < 1)
		return -1; /* malformed instruction */

	if (dst->word_count > *num_words)
		return -1; /* not enough data */

	dst->operands = *words;

	*words += dst->word_count;
	*num_words -= dst->word_count;
	return 0;
}

int sv_read(struct sv_module *dst, uint32_t *words, int num_words)
{
	/* check if we have enough data to read header */
	if (num_words < 5)
		return -1;

	dst->magic = *words++;
	dst->version = *words++;
	dst->generator = *words++;
	dst->bound = *words++;
	dst->reserved = *words++;

	/* verify header-data */
	if (dst->magic != SV_MAGIC ||
	    dst->version != 99)
		return -1;

	num_words -= 5;

	dst->instrs = NULL;
	dst->num_instrs = 0;
	while (num_words > 0) {
		struct sv_instr instr;
		if (sv_read_instr(&instr, &words, &num_words) < 0)
			return -1;

		dst->instrs = realloc(dst->instrs, (dst->num_instrs + 1) * sizeof(instr));
		if (!dst->instrs)
			return -1;

		dst->instrs[dst->num_instrs++] = instr;
	}

	return 0;
}

#include <stddef.h>
#include <stdio.h>

int main()
{
	struct sv_module mod;
	uint32_t word, *words = NULL;
	int num_words = 0, i;

	while (fread(&word, 4, 1, stdin) == 1) {
		words = realloc(words, (num_words + 1) * 4);
		if (!words) {
			perror("realloc");
			abort();
		}
		words[num_words++] = word;
	}

	printf("words: %d\n", num_words);

	if (sv_read(&mod, words, num_words) < 0) {
		fprintf(stderr, "failed to read SPIR-V module\n");
		return 1;
	}

	for (i = 0; i < mod.num_instrs; ++i)
		printf("opcode: %d\n", mod.instrs[i].opcode);

	return 0;
}
