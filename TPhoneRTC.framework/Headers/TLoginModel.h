//
//  TLoginModel.h
//  TPhoneRTC
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

/// 呼叫场景
typedef NS_ENUM(NSInteger, TPhoneRtcScence)
{
    TPhoneRtcScence_AGENTSCENCE = 1,      // 客服场景
    TPhoneRtcScence_OUTCALLSCENCE = 6,    // 外呼场景
};

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
//@property (nonatomic, copy, nonnull) NSString *bindTel;

/// 系统内部显示名称
@property (nonatomic, copy, nullable) NSString *showName;

/// 是否需要手机号外显
@property (nonatomic, assign) BOOL isTelExplicit;

/// 外部高级参数 ex: @{@"isOnline":@"true"}
@property (nonatomic, strong, nonnull) NSDictionary *advanceParams;


@end

@interface TCallModel : NSObject

/// 需要拨打的手机号
@property (nonatomic, copy, nonnull) NSString *number;
/// 客户外显号码
@property (nonatomic, copy, nullable) NSString *obClid;

/// 通话的唯一标识 如果不传 则SDK中会自动生成
@property (nonatomic, copy, nullable) NSString *requestUniqueId;

/// 呼叫类型（默认为外呼场景）
@property (nonatomic, assign) TPhoneRtcScence type;

/// 主叫号码（若不传，则回呼到SDK）
@property (nonatomic, copy, nullable) NSString *callerNumber;

/// 自定义参数 ex:@[@{@"name":@"xxxx",@"value":@"xxxx",@"type":@1},@{@"name":@"xxxx",@"value":@"xxxx",@"type":@1}]
@property (nonatomic, strong, nullable) NSArray *userField;


@end

NS_ASSUME_NONNULL_END
