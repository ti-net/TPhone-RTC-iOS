//
//  TLoginModel.h
//  TPhoneRTCSDK
//
//  Created by 马迪 on 2023/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 登录账号类型
static NSString *TPhoneLoginType_CrmIdAndPwd    = @"crmIdAndPwd"; // 员工和密码登录
static NSString *TPhoneLoginType_CnoAndToken    = @"conAndToken"; // 坐席编号和企业token登录

// 平台类型
static NSString *TPhonePlatformType_CT    = @"platformCTI"; // CT平台
static NSString *TPhonePlatformType_CL    = @"platformClink"; // CL平台

@interface TLoginModel : NSObject

/// 企业id
@property (nonatomic, copy, nonnull) NSString *enterpriseId;

/// 登录类型，crmId和crmPassword是一对鉴权方式，  cno和企业token是一对鉴权方式
@property (nonatomic, copy, nonnull) NSString *loginType;

/// 平台类型, CT/CL
@property (nonatomic, copy, nonnull) NSString *platformType;

/// 员工工号 / 座席工号
@property (nonatomic, copy, nonnull) NSString *loginKey;

/// 员工密码 / 企业token值
@property (nonatomic, copy, nonnull) NSString *loginSecret;

/// 绑定的手机号码
@property (nonatomic, copy, nonnull) NSString *bindTel;

/// 外部动态配置：是否需要调用上线接口(默认为是)。ex: @{@"isOnline":@"true"}
@property (nonatomic, strong, nonnull) NSDictionary *advanceParams;


@end

NS_ASSUME_NONNULL_END
