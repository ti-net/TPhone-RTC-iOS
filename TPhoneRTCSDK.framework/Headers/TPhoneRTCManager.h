//
//  TPhoneRTCManager.h
//  TPhoneRTCSDK
//
//  Created by 马迪 on 2023/3/14.
//

#import <Foundation/Foundation.h>
#import <TPhoneRTCSDK/TPhoneListener.h>
#import "TLoginModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TPhoneRTCManager : NSObject

+ (instancetype)sharedTPhoneRTCManager;

/**
 * 初始化对象
 * @param apiUrl 平台url
 * @param isDebug 是否Debug环境
 */
- (void)initSDK:(nullable NSString *)apiUrl setDebug:(BOOL)isDebug;

/**
 * 座席上线接口
 * @param loginModel 登录参数模型
 * @param webSocketDelegate 监听登录事件 CL专用
 * @param successBlock  登录成功的回调
 * @param errorBlock   登录失败的回调 [status:失败的错误码]
 *
 * 注: strCrmId和strCrmPassword是一对鉴权方式  strCno和strEnterpriseToken是一对鉴权方式
 */
- (void)loginTiPhone:(TLoginModel *)loginModel webSocketDelegate:(nullable id <TLoginMessageListener>)webSocketDelegate success:(nullable TSuccessCallback)successBlock error:(nullable TFailureCallback)errorBlock;

/**
 * 拨打电话
 * @param number 需要拨打的手机号
 * @param obClid 客户外显号码
 * @param requestUniqueId 通话的唯一标识 如果不传 则SDK中会自动生成
 * @param userField 自定义参数 ex: @{@"id":@"xxxxxxxx",@"workNum":@"xxxxxxx",@"depId":@"xxxxxx"}
 */
-(void)call:(NSString *)number obClid:(nullable NSString *) obClid
requestUniqueId:(nullable NSString*)requestUniqueId userField:(nullable NSDictionary *)userField;

/**
 * 外呼事件监听 ， 必须在登录之后调用
 * @param listener TiPhoneMessageListener接口的实例
 */
-(void)setOnEventListener:(id<TOnEventListener>)listener;

/**
 * 挂断电话
 */
-(void)hungUp;

/**
 * 退出登录
 */
- (void)logoutTiPhone:(nullable TSuccessCallback)successBlock error:(nullable TFailureCallback)errorBlock;

/**
 * 本地音频静音
 * @param muted  发送本地音频流(false:默认发送本地音频流  true：发送本地静音音频流）
 */
-(void)setMicrophoneMute:(BOOL)muted;

/**
 * 检查扬声器是否开启
 * @return true  扬声器已开启，语音会输出到扬声器
 * @return false 扬声器未开启，语音会输出到听筒
 */
-(BOOL)isSpeakerphoneEnabled;

/**
 * 启用/关闭扬声器
 * @param enabled 是否将音频外放(true：切换到外放  false：切换到听筒)
 */
-(void)setEnableSpeakerphone:(BOOL)enabled;

/**
 * 发送DTMF消息
 *
 * @param tones          所需要发送的DTMF消息.
*/
-(void)sendDTMF:(NSString *)tones;

/**
 * 获取sdk版本号
 * @return NSString* 版本号
 */
-(NSString *)getVersion;

/**
 * 接受邀请
 */
- (void)acceptedCall;

/**
 * 拒绝邀请
 */
- (void)refuseCall;



@end

NS_ASSUME_NONNULL_END
