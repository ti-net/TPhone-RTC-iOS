//
//  TPhoneRTCManager.h
//  TPhoneRTC
//
//  Created by 马迪 on 2023/3/14.
//

#import <Foundation/Foundation.h>
#import <TPhoneRTC/TPhoneListener.h>
#import "TLoginModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TPhoneRTCManager : NSObject

+ (instancetype)sharedTPhoneRTCManager;

/**
 * 初始化对象
 * @param apiUrl 平台url
 * @param debug 是否Debug环境
 */
- (void)initSDK:(nullable NSString *)apiUrl isDebug:(BOOL)debug;

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
 * @param callModel 外呼参数
 */
-(void)call:(TCallModel *)callModel;

/**
 * 外呼事件监听 ， 必须在登录之后调用
 * @param listener TiPhoneMessageListener接口的实例
 */
-(void)setOnEventListener:(id<TOnEventListener>)listener;

/**
 设置事件监听 需要在登录成功之后调用
@param listener TIncomingMessageListener接口的实例
*/
- (void)setIncomingMessageListener:(id<TIncomingMessageListener>)listener;
/**
 * 挂断电话
 */
-(void)hangup;

/**
 * 退出登录
 */
- (void)logoutTiPhone:(nullable TSuccessCallback)successBlock error:(nullable TFailureCallback)errorBlock;

/**
 * 本地音频静音
 * @param muted  发送本地音频流(NO:默认发送本地音频流 YES：发送本地静音音频流）
 */
-(void)setMicrophoneMute:(BOOL)muted;

/**
 * 检查扬声器是否开启
 * @return YES  扬声器已开启，语音会输出到扬声器
 * @return NO 扬声器未开启，语音会输出到听筒
 */
-(BOOL)isSpeakerphoneEnabled;

/**
 * 启用/关闭扬声器
 * @param enabled 是否将音频外放(YES：切换到外放  NO：切换到听筒)
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
 * 接受回呼邀请
 */
- (void)acceptCall;

/**
 * 拒绝邀请
 */
- (void)refuseCall;



@end

NS_ASSUME_NONNULL_END
