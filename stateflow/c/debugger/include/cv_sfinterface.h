/* Copyright 1999-2013 The MathWorks, Inc. */

/*  
 *  cv_sfinterface.h
 *
 *  Routines to interface with cv.dll by way of function pointers 
 *  locally stored.
 */

#ifndef __cv_sfinterface__
#define __cv_sfinterface__

#include <stdio.h>

#ifndef CV_EML_CHECK_TYPE_DEF
#define CV_EML_CHECK_TYPE_DEF

typedef enum {
    CV_EML_FCN_CHECK = 0,
    CV_EML_IF_CHECK,
    CV_EML_FOR_CHECK,
    CV_EML_WHILE_CHECK,
    CV_EML_COND_CHECK,
    CV_EML_MCDC_CHECK,
    CV_EML_SWITCH_CHECK,
    CV_EML_TESTOBJECTIVE_CHECK,
    CV_EML_CHECK_CNT
}SfCvEmlCheckType;

#endif

#ifndef CV_SCRIPT_CHECK_TYPE_DEF
#define CV_SCRIPT_CHECK_TYPE_DEF

typedef enum {
    CV_SCRIPT_FCN_CHECK = 0,
    CV_SCRIPT_IF_CHECK,
    CV_SCRIPT_FOR_CHECK,
    CV_SCRIPT_WHILE_CHECK,
    CV_SCRIPT_COND_CHECK,
    CV_SCRIPT_MCDC_CHECK,
    CV_SCRIPT_SWITCH_CHECK,
    CV_SCRIPT_TESTOBJECTIVE_CHECK,
    CV_SCRIPT_CHECK_CNT
}SfCvScriptCheckType;

#endif

#define NUM_REPEAT_TYPES 4

/******************************************************************************/

typedef struct CvSfInterfaceInfoStruct {
    bool covEnabled;

    int (*relationalopInitFcn) ( unsigned int cvId, 
                                unsigned int relopCnt,
                                int *txtStartIdx,
                                int *txtEndIdx,
                                int *relationalEps);

    int (*relationalopUpdateFcn) ( unsigned int cvId, 
                                unsigned int relopIdx,
                                double lhsVal, double rhsVal,
                                double relationalopEps);

    int (*saturationInitFcn)   ( unsigned int cvId, 
                                unsigned int satCnt,
                                int *txtStartIdx,
                                int *txtEndIdx);

    int (*saturationUpdateFcn) ( unsigned int cvId, 
                                unsigned int satIdx,
                                int val);

    int (*saturationUpdateAccumFcn) ( unsigned int cvId, 
                                unsigned int satIdx,
                                unsigned int accumMode);


    int (*testobjectiveInitFcn)  ( unsigned int cvId, 
                                unsigned int testobjectiveCnt, 
                                unsigned int *txtStartIdx, 
                                unsigned int *txtEndIdx);

    int (*testobjectiveUpdateFcn)  ( unsigned int cvId,
                                unsigned int objectIndex,
                                unsigned int retValue);

    
    int (*transInitFcn)       ( unsigned int cvId, 
                                int predicateCnt, 
                                unsigned int *txtStartIdx, 
                                unsigned int *txtEndIdx,
                                unsigned int postFixPredicateTreeCount,
                                int *postFixPredicateTree);

    int (*stateInitFcn)       ( unsigned int cvId, 
                                unsigned int numChild, 
                                bool hasDuringSwitch,
                                bool hasExitSwitch,
                                bool hasHistSwitch,
                                unsigned int onDecCnt,
                                unsigned int *decStartInd,
                                unsigned int *decEndInd);

    int (*chartInitFcn)       ( unsigned int cvId, 
                                unsigned int numChild, 
                                bool hasDuringSwitch,
                                bool hasExitSwitch,
                                bool hasHistSwitch);

    int (*decUpdateFcn)       ( unsigned int cvId,
                                unsigned int objectIndex,
                                unsigned int retValue);

    int (*condUpdateFcn)      ( unsigned int cvId,
                                unsigned int objectIndex,
                                unsigned int retValue);

    int (*sigUpdateFcn)       ( unsigned int cvId, 
                                unsigned int dataNumber, 
                                double equivValue);

    int (*emlScriptInitFcn)   ( unsigned int cvId, 
                                unsigned int fcnCnt,
                                unsigned int ifCnt,
                                unsigned int testobjectiveCnt,
	                        unsigned int saturationCnt,
                                unsigned int switchCnt,
                                unsigned int forCnt,
                                unsigned int whileCnt,
                                unsigned int condCnt,
                                unsigned int mcdcCnt);

    int (*emlFcnInitFcn)      ( unsigned int cvId, 
                                unsigned int fcnIdx,
                                const char *name,
                                int charStart,
                                int charExprEnd,
                                int charEnd);
    int (*emlTestobjectiveInitFcn)      ( unsigned int cvId, 
                                unsigned int fcnIdx,
                                const char *name,
                                int charStart,
                                int charExprEnd,
                                int charEnd);
    int (*emlSaturationInitFcn)      ( unsigned int cvId, 
                                unsigned int fcnIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*emlIfInitFcn)       ( unsigned int cvId, 
                                unsigned int ifIdx,
                                int charStart,
                                int charExprEnd,
                                int charElseStart,
                                int charEnd);

    int (*emlSwitchInitFcn)   ( unsigned int cvId, 
                                unsigned int switchIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd,
                                unsigned int caseCnt,
                                int *caseStart,
                                int *caseExprEnd);

    int (*emlForInitFcn)      ( unsigned int cvId, 
                                unsigned int forIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*emlWhileInitFcn)    ( unsigned int cvId, 
                                unsigned int whileIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*emlMCDCInitFcn)     ( unsigned int cvId, 
                                unsigned int mcdcIdx,
                                int charStart,
                                int charEnd,
                                unsigned int condCnt,
                                unsigned int firstCondIdx,
                                int *condStart,
                                int *condEnd,
                                unsigned int pfxLength,
                                int *pfixExpr);

    int (*emlRelationalInitFcn)     ( unsigned int cvId, 
                                unsigned int objIdx,
                                int charStart,
                                int charEnd,
                                double relationalEps);

    int (*emlFcnEval)         ( unsigned int cvId, unsigned int index);

    int (*emlTestobjectiveEval)         ( unsigned int cvId, unsigned int index, int val);

    int (*emlIfEval)          ( unsigned int cvId, unsigned int index, int val);

    int (*emlForEval)         ( unsigned int cvId, unsigned int index, int val);

    int (*emlWhileEval)       ( unsigned int cvId, unsigned int index, int val);

    int (*emlSwitchEval)      ( unsigned int cvId, unsigned int index, int val); 

    int (*emlCondEval)        ( unsigned int cvId, unsigned int index, int val);

    int (*emlMcdcEval)        ( unsigned int cvId, unsigned int index, int val); 

    int (*scriptInitFcn)   ( unsigned int cvId, 
                                unsigned int fcnCnt,
                                unsigned int ifCnt,
                                unsigned int testobjectiveCnt,
				unsigned int saturationCnt,
                                unsigned int switchCnt,
                                unsigned int forCnt,
                                unsigned int whileCnt,
                                unsigned int condCnt,
                                unsigned int mcdcCnt);

    int (*scriptFcnInitFcn) ( unsigned int cvId, 
                                unsigned int fcnIdx,
                                const char *name,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*scriptTestobjectiveInitFcn) ( unsigned int cvId, 
                                unsigned int fcnIdx,
                                const char *name,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*scriptSaturationInitFcn) ( unsigned int cvId, 
                                unsigned int fcnIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*scriptIfInitFcn)       ( unsigned int cvId, 
                                unsigned int ifIdx,
                                int charStart,
                                int charExprEnd,
                                int charElseStart,
                                int charEnd);

    int (*scriptSwitchInitFcn)   ( unsigned int cvId, 
                                unsigned int switchIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd,
                                unsigned int caseCnt,
                                int *caseStart,
                                int *caseExprEnd);

    int (*scriptForInitFcn)      ( unsigned int cvId, 
                                unsigned int forIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*scriptWhileInitFcn)    ( unsigned int cvId, 
                                unsigned int whileIdx,
                                int charStart,
                                int charExprEnd,
                                int charEnd);

    int (*scriptMCDCInitFcn)     ( unsigned int cvId, 
                                unsigned int mcdcIdx,
                                int charStart,
                                int charEnd,
                                unsigned int condCnt,
                                unsigned int firstCondIdx,
                                int *condStart,
                                int *condEnd,
                                unsigned int pfxLength,
                                int *pfixExpr);
    int (*scriptRelationalInitFcn)     ( unsigned int cvId, 
                            unsigned int objIdx,
                            int charStart,
                            int charEnd,
                            double relationalEps);

    int (*scriptFcnEval)         ( unsigned int cvId, unsigned int index);

    int (*scriptTestobjectiveEval)         ( unsigned int cvId, unsigned int index, int val);

    int (*scriptIfEval)          ( unsigned int cvId, unsigned int index, int val);

    int (*scriptForEval)         ( unsigned int cvId, unsigned int index, int val);

    int (*scriptWhileEval)       ( unsigned int cvId, unsigned int index, int val);

    int (*scriptSwitchEval)      ( unsigned int cvId, unsigned int index, int val); 

    int (*scriptCondEval)        ( unsigned int cvId, unsigned int index, int val);

    int (*scriptMcdcEval)        ( unsigned int cvId, unsigned int index, int val); 


} CvSfInterfaceInfo;

#define STATIC_INIT_CVSF_INTERFACE {false, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,\
            NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,          \
            NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,          \
            NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,          \
            NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}


/*
 * Gateway Functions
 */
extern void cv_init_saturation(  unsigned int cvId,
                        unsigned int satCnt,
                        unsigned int *txtStartIdx, 
                        unsigned int *txtEndIdx);

extern void cv_init_relationalop(  unsigned int cvId,
                        unsigned int satCnt,
                        unsigned int *txtStartIdx, 
                        unsigned int *txtEndIdx,
                        int *relationalEps);

extern void cv_init_testobjective(unsigned int cvId, 
                    unsigned int testobjectiveCnt, 
                    unsigned int *txtStartIdx, 
                    unsigned int *txtEndIdx);

extern void cv_init_trans(unsigned int cvId, 
                    int predicateCnt, 
                    unsigned int *txtStartIdx, 
                    unsigned int *txtEndIdx,
                    unsigned int postFixPredicateTreeCount,
                    int *postFixPredicateTree);


extern void cv_init_state(unsigned int cvId, 
                          unsigned int numChild, 
                          bool hasDuringSwitch,
                          bool hasExitSwitch,
                          bool hasHistSwitch,
                          unsigned int onDecCnt,
                          unsigned int *decStartInd,
                          unsigned int *decEndInd);

extern void cv_init_chart(unsigned int cvId, 
                          unsigned int numChild, 
                          bool hasDuringSwitch,
                          bool hasExitSwitch,
                          bool hasHistSwitch);

extern void cv_dec_update_call(unsigned int cvId,
                           unsigned int objectIndex,
                           unsigned int retValue);

extern void cv_sigrange_update( unsigned int cvId, 
                                unsigned int dataNumber, 
                                double equivValue);

extern void cv_testobjective_update_call(unsigned int cvId,
						   unsigned int objectIdx,
						   unsigned int retValue);



/*
 * EML Gateway Functions
 */

extern void cvsf_eml_eval( unsigned int cvId,
                         SfCvEmlCheckType checkType,
                         unsigned int objectIndex,
                         int retValue);

extern void cvsf_eval_relational(unsigned int cvId,
                            unsigned int objectIndex,
                            double lhsv,
                            double rhsv,
                            double relationalEps);

extern void cvsf_eml_init_script( unsigned int cvId,
                                  unsigned int fcnCnt,
                                  unsigned int ifCnt,
                                  unsigned int testobjectiveCnt,
				  unsigned int saturationCnt,
                                  unsigned int switchCnt,
                                  unsigned int forCnt,
                                  unsigned int whileCnt,
                                  unsigned int condCnt,
                                  unsigned int mcdcCnt);

extern void cvsf_eml_init_fcn( unsigned int cvId,
                               unsigned int fcnIdx,
                               const char *name,
                               int charStart,
                               int charExprEnd,
                               int charEnd);
extern void cvsf_eml_init_testobjective( unsigned int cvId,
                               unsigned int fcnIdx,
                               const char *name,
                               int charStart,
                               int charExprEnd,
                               int charEnd);
extern void cvsf_eml_init_saturation( unsigned int cvId,
                               unsigned int fcnIdx,
                               int charStart,
                               int charExprEnd,
                               int charEnd);

extern void cvsf_eml_init_if( unsigned int cvId,
                              unsigned int ifIdx,
                              int charStart,
                              int charExprEnd,
                              int charElseStart,
                              int charEnd);

extern void cvsf_eml_init_switch( unsigned int cvId,
                                  unsigned int switchIdx,
                                  int charStart,
                                  int charExprEnd,
                                  int charEnd,
                                  unsigned int caseCnt,
                                  int *caseStart,
                                  int *caseExprEnd);

extern void cvsf_eml_init_for( unsigned int cvId,
                               unsigned int forIdx,
                               int charStart,
                               int charExprEnd,
                               int charEnd);


extern void cvsf_eml_init_while( unsigned int cvId,
                                 unsigned int whileIdx,
                                 int charStart,
                                 int charExprEnd,
                                 int charEnd); 

extern void cvsf_eml_init_mcdc( unsigned int cvId,
                                unsigned int mcdcIdx,
                                int charStart,
                                int charEnd,
                                unsigned int condCnt,
                                unsigned int firstCondIdx,
                                int *condStart,
                                int *condEnd,
                                unsigned int pfxLength,
                                int *pfixExpr);

extern void cvsf_eml_init_relational( unsigned int cvId,
                                unsigned int objIdx,
                                int charStart,
                                int charEnd,
                                double relationalEps);


extern void cvsf_script_eval( unsigned int cvId,
                         SfCvEmlCheckType checkType,
                         unsigned int objectIndex,
                         int retValue);


extern void cvsf_script_init_script( unsigned int cvId,
                                  unsigned int fcnCnt,
                                  unsigned int ifCnt,
                                  unsigned int testobjectiveCnt,
				  unsigned int saturationCnt,
                                  unsigned int switchCnt,
                                  unsigned int forCnt,
                                  unsigned int whileCnt,
                                  unsigned int condCnt,
                                  unsigned int mcdcCnt);

extern void cvsf_script_init_fcn( unsigned int cvId,
                               unsigned int fcnIdx,
                               const char *name,
                               int charStart,
                               int charExprEnd,
                               int charEnd);
extern void cvsf_script_init_testobjective( unsigned int cvId,
                               unsigned int fcnIdx,
                               const char *name,
                               int charStart,
                               int charExprEnd,
                               int charEnd);

extern void cvsf_script_init_saturation( unsigned int cvId,
                               unsigned int satIdx,
                               int charStart,
                               int charExprEnd,
                               int charEnd);

extern void cvsf_script_init_if( unsigned int cvId,
                              unsigned int ifIdx,
                              int charStart,
                              int charExprEnd,
                              int charElseStart,
                              int charEnd);

extern void cvsf_script_init_switch( unsigned int cvId,
                                  unsigned int switchIdx,
                                  int charStart,
                                  int charExprEnd,
                                  int charEnd,
                                  unsigned int caseCnt,
                                  int *caseStart,
                                  int *caseExprEnd);

extern void cvsf_script_init_for( unsigned int cvId,
                               unsigned int forIdx,
                               int charStart,
                               int charExprEnd,
                               int charEnd);


extern void cvsf_script_init_while( unsigned int cvId,
                                 unsigned int whileIdx,
                                 int charStart,
                                 int charExprEnd,
                                 int charEnd); 

extern void cvsf_script_init_mcdc( unsigned int cvId,
                                unsigned int mcdcIdx,
                                int charStart,
                                int charEnd,
                                unsigned int condCnt,
                                unsigned int firstCondIdx,
                                int *condStart,
                                int *condEnd,
                                unsigned int pfxLength,
                                int *pfixExpr);

extern void cvsf_script_init_relational( unsigned int cvId,
                                unsigned int objIdx,
                                int charStart,
                                int charEnd,
                                double relationalEps);

/*
 * Initialization Functions
 */
extern void cv_create_interface(const char *machName);
extern void cv_destroy_interface(void);
extern void cv_create_instance_objects(unsigned int *states, 
                                unsigned int stateCount,
                                unsigned int *transitions,
                                unsigned int transCount,
										unsigned int *dataIdx,
										unsigned int dataCount,
                                unsigned int *chartId,
                                unsigned int chartSfId, 
                                const char *fullPath);

/* Opaque type */
typedef struct SfDebugInstanceStruct DBInstanceStruct;


extern void sf_debug_cv_initialize_instance(DBInstanceStruct *debugInstance,
                                     unsigned int machineNumber,
                                     unsigned int chartNumber,
                                     unsigned int instanceNumber);

extern void sf_debug_cv_initialize_script(DBInstanceStruct   *debugInstance,
                             unsigned int machineNumber,
                             unsigned int chartNumber,
                             unsigned int scriptNumber,
                             unsigned int scriptId,
                             unsigned int chartId); 

extern void sf_debug_cv_terminate_chart(DBInstanceStruct *debugInstance,
                                    unsigned int machineNumber,
                                    unsigned int chartNumber);


extern bool cv_is_enabled(void);

extern void cv_cond_update_call(unsigned int cvId,
                                unsigned int objectIndex,
                                unsigned int retValue);

extern void cv_saturation_update_call(unsigned int cvId,
                                  unsigned int satIdx,
                                  unsigned int retValue);


extern void cv_saturation_update_call(unsigned int cvId,
                                  unsigned int satIdx,
                                  unsigned int retValue);
extern void cv_saturation_update_accum(unsigned int cvId,
                                  unsigned int satIdx,
                                  unsigned int accumMode);

#endif
