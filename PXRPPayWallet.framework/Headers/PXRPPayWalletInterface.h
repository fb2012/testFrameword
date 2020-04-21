//
//  PXRPPayWalletInterface.h
//  PXRPPayWallet
//
//  Created by ice on 2019/11/17.
//  Copyright © 2019 ice. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PXRPPayWalletObject.h"
NS_ASSUME_NONNULL_BEGIN

@protocol PXRPPayWalletDelegate;
@interface PXRPPayWalletInterface : NSObject
/// 钱包状态
@property (nonatomic, readonly) PXRPPayWalletStatus walletStatus;
/// 使用单列操作钱包，SDK维护单列的生命周期
+ (instancetype)shareInstance;

/*! @brief 注册用户
 * @param appid 从PXRPPay获取的App标识
 * @param user 当前用户
 * @param delegate 代理
*/
- (void)registerApp:(NSString *)appid withUser:(PXRPPayUser *)user delegate:(id<PXRPPayWalletDelegate>)delegate;

/// 注册 pay
/// @param appInfo info
/// @param user user
/// @param delegate delegate description
- (void)registerPayByApp:(NSDictionary *)appInfo withUser:(PXRPPayUser *)user delegate:(id<PXRPPayWalletDelegate>)delegate;

/// 登出并清理前一个用户的信息
- (void)logout;

#pragma mark - 支付中心
/*! @brief  显示钱包页面（支付中心）
 * 函数调用后，会切换到PXRPPay的钱包页面，用户返回时回到vc
 */
- (void)pushWalletPageOnViewController:(UIViewController *)vc;

/// 获取SDK中的deviceid 
- (NSString *)getSystemWalletDeviceId;

#pragma mark - 付款码页面
/*! @brief  显示付款码页面
* 函数调用后，会切换到PXRPPay的付款码页面，用户返回时回到vc
*/
- (void)pushPayCodePageOnViewContorller:(UIViewController *)vc;

#pragma mark - 二维码支付
///  判断二维码是不是PXRPPay支持的格式
+ (PXRPPayScanCodeType)isPXRPPayQrCode:(NSString *)code;

/*! @brief 二维码支付
 * 函数调用后，会切换到PXRPPay的二维码支付确认页，完成后调用completion并返回当前vc
 * @param vc 当前页面
 * @param code 支付二维码
 * @param trandNo  静态码必传 其他可以不传 用来标识该笔转账，16位UUID，订单Id  自己生成
 * @param notifyParams 通知参数
 * @param completion 支付回调
 */
- (void)pushPaymentPageOnViewController:(UIViewController *)vc qrCode:(NSString *)code trandeNo:(NSString *)trandNo notifyParams:(NSString *)notifyParams completion:(void(^)(PXRPPayPaymentResult *))completion;

#pragma mark - 转账
/*! @brief 转账给其他用户
 * 函数调用后，会切换到PXRPPay的转账页，完成后调用completion并返回当前vc
 * @param vc 当前页面
 * @param user 转账接收方
 * @param tradeNo 转账Id，用来标识该笔转账，16位UUID，订单Id  自己生成
 * @param notifyParams 通知参数
 * @param completion 支付回调（succeed：是否成功，amount：转账金额）
 */
- (void)pushTransferSendPageOnViewController:(UIViewController *)vc toUser:(PXRPPayUser *)user tradeNo:(NSString *)tradeNo notifyParams:(NSString *)notifyParams completion:(void(^)(PXRPPayTransferResult *result))completion;

/*! @brief 转账收款
 * 函数调用后，会切换到PXRPPay的转账收款页，完成后调用completion并返回当前vc
 * @param vc 当前页面
 * @param tradeNo 转账Id，用来标识该笔转账，16位UUID，订单Id 自己生成
 * @param fromMe 是否自己发出 YES:当前用户是发出方
 * @param notifyParams 通知参数
 * @param completion 支付回调（succeed：是否成功，amount：转账金额）
*/
- (void)pushTransferReceivePageOnViewController:(UIViewController *)vc tradeNo:(NSString *)tradeNo fromMe:(BOOL)fromMe notifyParams:(NSString *)notifyParams completion:(void(^)(PXRPPayTransferResult *result))completion;

#pragma mark - 账单详情
/*! @brief 查看账单详情
 * 函数调用后，会切换到PXRPPay的账单详情页，后退返回当前vc
 * @param vc 当前页面
 * @param tradeNo PayBy订单
*/
- (void)pushBillDetailPageOnViewController:(UIViewController *)vc tradeNo:(NSString *)tradeNo;

#pragma mark - 红包
/// @brief 发送群红包
/// @param vc 当前页面
/// @param tradeNo 商户订单Id，用来标识该笔交易 UUID
/// @param group 红包发出的群
/// @param notifyParams 通知参数
/// @param completion 支付回调
- (void)pushRedPacketOnViewController:(UIViewController *)vc tradeNo:(NSString *)tradeNo fromGroup:(PXRPPayGroup *)group notifyParams:(NSString *)notifyParams completion:(void(^)(PXRPPayRedPacketResult *result))completion;

/// @brief 接收红包
/// @param vc 当前页面
/// @param tradeNo 领取的商户订单号
/// @param sentTradeNo 发送的商户订单号
/// @param group 红包发出的群
/// @param fromMe 是否是自己发出 YES：当前用户发出
/// @param notifyParams 通知参数
/// @param completion 支付回调
- (void)pushRedPacketReceivePageOnViewController:(UIViewController *)vc tradeNo:(NSString *)tradeNo sentTradeNo:(NSString *)sentTradeNo fromGroup:(PXRPPayGroup *)group fromMe:(BOOL)fromMe notifyParams:(NSString *)notifyParams completion:(void(^)(PXRPPayRedPacketResult *result))completion;


@end


/* ------------------------------------------- */
@protocol PXRPPayWalletDelegate <NSObject>
@required
/// 当前用户AccessToken已过期，需要更新，更新完成后回调；若失败设置Error
- (void)PXRPPayWallet:(PXRPPayWalletInterface *)wallet didUserExpired:(PXRPPayUser *)user updatedThen:(void(^)(PXRPPayUser * _Nonnull payUser, NSError * __nullable error))updatedThen;
/// 更新用户头像 和昵称
- (void)PXRPPayWallet:(PXRPPayWalletInterface *)wallet didSetupAvatarWithUserId:(NSString *)userId completion:(void(^)(UIImage * __nullable image,NSURL *  __nullable url,NSString *nickName, NSError * __nullable error))completion;


/// 发送转账或红包时回调，需要重新传tradNo
/// @param wallet wallet description
/// @param type PXRPPayWalletInterface
/// @param userId user id
/// @param updatedThen 回调TradNo 不重复。16位UUID，订单Id 自己生成
- (void)PXRPPayWallet:(PXRPPayWalletInterface *)wallet andType:(PXRPPayTradeNoType)type TransferSend:(NSString *)userId updatedThen:(void (^)(NSString *tradeNo, NSError * __nullable error))updatedThen;


/// 请求跳转到扫码页面
- (void)PXRPPayWalletDidOpenScanPage:(PXRPPayWalletInterface *)wallet;
/**
 请求跳转到好友转账列表
 */
- (void)PXRPPayWalletDidOpenTransferFriendsListPage:(PXRPPayWalletInterface *)wallet;


@optional
/// 钱包SDK注册成功
- (void)PXRPPayWalletDidRegistered:(PXRPPayWalletInterface *)wallet;
/// 钱包SDK注册失败
- (void)PXRPPayWallet:(PXRPPayWalletInterface *)wallet didRegisterFailWithErrorCode:(PXRPPayErrorCode )errorCode context:(NSString *)context;
///  请求跳转到好友转账列表
/// @param wallet wallet description
/// @param page 当前ViewController ，可以直接 push
/// @param completion 选择的user 和 转账Id，用来标识该笔转账，16位UUID，订单Id  自己生成
- (void)PXRPPayWalletDidOpenTransferFriendsListPage:(PXRPPayWalletInterface *)wallet JumpOfSDKPage:(UIViewController *)page  completion:(void(^)(PXRPPayUser *toUser, NSString *tradeNo))completion DEPRECATED_MSG_ATTRIBUTE("Use -PXRPPayWalletDidOpenTransferFriendsListPage: instead.");

@end


NS_ASSUME_NONNULL_END
