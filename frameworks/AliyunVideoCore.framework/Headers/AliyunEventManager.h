//
//  AliyunEventManager.h
//  QUSDK
//
//  Created by Worthy on 2017/8/23.
//  Copyright © 2017年 Alibaba Group Holding Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DefaultEventManager [AliyunEventManager sharedManager]

typedef NS_ENUM(NSInteger, AliyunEvent) {
    AliyunEventRecordInit = 2001,
    AliyunEventRecordStart,
    AliyunEventRecordStop,
    AliyunEventRecordDelete,
    AliyunEventRecordFinish,
    AliyunEventRecordError,
    AliyunEventRecordPaster,
    AliyunEventRecordMusic,
    AliyunEventRecordFilter,
    AliyunEventRecordRate,
    AliyunEventRecordBeauty,
    AliyunEventRecordPosition,
    AliyunEventEditInit = 3001,
    AliyunEventEditFilter = 3005,
    AliyunEventEditMV,
    AliyunEventEditExportStart = 3011,
    AliyunEventEditExportCancel,
    AliyunEventEditExportError = 3016,
    AliyunEventEditExportFinish,
    AliyunEventTranscodeStart = 8001,
    AliyunEventTranscodeCancel,
    AliyunEventTranscodeError,
    AliyunEventTranscodeFinish,
    
    
    AliyunEventUploadAddFile = 20001,
    AliyunEventUploadStarted,
    AliyunEventUploadSucceed,
    AliyunEventUploadFailed,
    AliyunEventUploadPartStarted,
    AliyunEventUploadPartFailed,
    AliyunEventUploadPartCompleted,
    
};

extern NSString * const AliyunEventProductKey;
extern NSString * const AliyunEventProductPlayer;
extern NSString * const AliyunEventProductPusher;
extern NSString * const AliyunEventProductMixer;
extern NSString * const AliyunEventProductSvideo;
extern NSString * const AliyunEventProductUpload;


extern NSString * const AliyunEventModuleKey;
extern NSString * const AliyunEventModuleSaasPlayer;
extern NSString * const AliyunEventModulePaasPlayer;
extern NSString * const AliyunEventModuleMixer;
extern NSString * const AliyunEventModulePublisher;
extern NSString * const AliyunEventModuleSvideoBase;
extern NSString * const AliyunEventModuleSvideoStandard;
extern NSString * const AliyunEventModuleSvideoPro;
extern NSString * const AliyunEventModuleUploader;

extern NSString * const AliyunEventVersionKey;


@interface AliyunEventManager : NSObject

@property (nonatomic, copy) NSString *requestID;
// 是否开启
@property (nonatomic, assign) BOOL enabled;

+ (instancetype)sharedManager;

- (void)sendEvent:(AliyunEvent)event params:(NSDictionary *)params __attribute__((deprecated("This method will not send necessary common parameters such as sdk version.")));

- (void)sendEvent:(AliyunEvent)event params:(NSDictionary *)params commonParams:(NSDictionary *)commonParams;

- (void)refreshRequestID;

@end
