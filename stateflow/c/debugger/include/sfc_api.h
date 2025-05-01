/*
 *   SFC_API.H  Stateflow S-Function API header file.
 *
 *   Copyright 1995-2012 The MathWorks, Inc.
 *
 */

/*! \file
 * \brief Exposes gateway function into the debugger API
 */

#ifndef _SFC_API_H_
#define _SFC_API_H_

#ifdef __cplusplus
extern "C" {
#endif

    extern unsigned int sf_debug_api(SfDebugInstanceStruct* debugInstance, int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif /* _SFC_API_H_ */
