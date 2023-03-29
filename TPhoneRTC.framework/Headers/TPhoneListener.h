//
//  TPhoneListener.h
//  TiPhoneSDK
//
//  Created by 马迪 on 2022/10/11.
//

#ifndef TPhoneListener_h
#define TPhoneListener_h

#pragma mark - onEventChange 事件的 Message Code

const static int ON_CALLING_START                               = 100;      // 开始外呼,同时返回 requestUniqueId
const static int ON_RINGING                                     = 101;      // 开始播放铃声
const static int ON_CALL_CANCELLED                              = 102;      // 外呼已取消
const static int ON_CALL_REFUSED                                = 103;      // 呼叫被拒绝
const static int ON_CALLING                                     = 104;      // 呼叫中
const static int ON_CALLING_END                                 = 105;      // 外呼结束,同时返回结束原因，1 表示对方挂断，0 表示己方挂断
const static int ERR_RTC_CALL_FAILED_PARAMS_INCORRECT           = 200;      // 外呼失败----参数不正确
const static int ERR_RTC_CALL_FAILED_CALL_REPEAT                = 201;      // 外呼失败----重复呼叫
const static int ERR_RTC_CALL_FAILED_REMOTE_OFFLINE             = 202;      // 通话过程中对端异常挂断
const static int ERR_RTC_CALL_FAILED_NET_ERROR                  = 203;      // 外呼失败----网络异常
const static int ERR_RTC_CALL_FAILED_RTM_ERROR                  = 204;      // 外呼失败----内部信令错误

#pragma mark - 通用 TFailureCallback 错误码

const static int ErrNetwork                                     = 5001;     // 网络请求错误
const static int ErrorTokenExpired                              = 5002;     // AccessToken已过期
const static int ErrorNotInit                                   = 5003;     // 引擎未初始化
const static int ErrorInit                                      = 5004;     // 初始化错误
const static int ErrorAuth                                      = 5005;     // 鉴权错误
const static int ErrorLogin                                     = 5006;     // 上线错误

/// 网络状态
typedef NS_ENUM(NSInteger, TPhoneRtcNetwotkQuality)
{
    TPhoneRtcNetwotkQuality_Unknown,      // 网络质量未知
    TPhoneRtcNetwotkQuality_Good ,      // 网络质量较好
    TPhoneRtcNetwotkQuality_General ,    // 网络质量一般
    TPhoneRtcNetwotkQuality_Bad ,    // 网络质量较差
};

typedef void (^TSuccessCallback)(NSString * _Nullable data);
typedef void (^TFailureCallback)(NSInteger code, NSString * _Nullable msg);

@protocol TOnEventListener <NSObject>

/**
* 错误回调
*
* @param errCode 错误码
* @param errMsg 错误描述
*/
- (void)onEventError:(int)errCode errMsg:(nullable NSString *)errMsg;

/**
* 事件回调
*
* @param eventId 事件标识
* @param message 返回信息
*/
- (void)onEventChange:(int)eventId message:(nullable NSString *)message;

/**
 * 拉取的对端的音频格式
 *
 * @param samples 采样率
 * @param channels 声道数
 */
- (void)receiveStreamSample:(int)samples channels:(int)channels;

/**
 * 拉取到的对方的数据流
 *
 * @param data 对方原始数据
 * @param size 数据大小
 */
- (void)receiveStreamDataFromOther:(void *_Nonnull)data size:(int)size;


/// 本地网络质量
- (void)localNetworkQuality:(TPhoneRtcNetwotkQuality)netwotkQuality;

/**
* 接收到远端呼叫
*
*  @param fields 包含如下数据：
*
* customerNumber：主叫号码
* requestUniqueId：通话唯一标识
*
*/
- (void)onRemoteInvitationReceived:(nonnull NSDictionary *)fields;

/**
* 远端呼叫已拒绝
*
* @param fields 包含如下数据：
*
* customerNumber：主叫号码
* requestUniqueId：通话唯一标识
* isCalling：标识本次邀请是否因正处于通话中而自动拒绝 YES：是，NO：否
*
*/
- (void)onInvitationRefusedByLocal:(nonnull NSDictionary *)fields;

/**
* 远端呼叫已取消
*
* @param fields 包含如下数据：
*
* customerNumber：主叫号码
* requestUniqueId：通话唯一标识
*
*/
- (void)onRemoteInvitationCanceled:(nonnull NSDictionary *)fields;

/**
* 接收回呼失败
*
* @param fields 包含如下数据：
*
* customerNumber：主叫号码
* requestUniqueId：通话唯一标识
*
*/
- (void)onRemoteInvitationFailure:(nonnull NSDictionary *)fields;

@end

@protocol TLoginMessageListener <NSObject>

- (void)onLoginMessageError:(int32_t)errCode errMsg:(nullable NSString *)errMsg;

- (void)onLoginMessageSuccess:(NSString* _Nullable)message;

- (void)onLoginMessagWebSocketMessage:(NSString* _Nullable)message;

@end

@protocol TIncomingMessageListener <NSObject>

- (void)onIncomingMessage:(NSString* _Nullable)message;

@end




#endif /* TPhoneListener_h */
