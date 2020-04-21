//
//  PXRPPayByWalletInterface.h
//  PXRPPayWallet
//
//  Created by ice on 2020/4/7.
//  Copyright © 2020 ice. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PXRPKYCStatusInfoModel.h"
 typedef NS_ENUM(NSInteger ,PXRPWalletFunType) {
     PXRPWalletFunTypePayCode,
     PXRPWalletFunTypeWallet,
     PXRPWalletFunTypeScan,
     PXRPWalletFunTypeTransfer,
     PXRPWalletFunTypeCollect,
     PXRPWalletFunTypeAddMoney,
     PXRPWalletFunTypeCashNow,
     PXRPWalletFunTypeCashGift,
     PXRPWalletFunTypeEATM,
     PXRPWalletFunTypeCashDelivery,
     PXRPWalletFunTypeShopping,
     PXRPWalletFunTypeTopup,
     PXRPWalletFunTypeFunMore,
     
     PXRPWalletFunTypeSecurity,
     PXRPWalletFunTypeMethodPriority,
     PXRPWalletFunTypeForgotPaymentPassword,
     PXRPWalletFunTypeHelpCenter,
     PXRPWalletFunTypeWithdraw,
     PXRPWalletFunTypeEidVerity,
     PXRPWalletFunTypeBill,

 };

typedef NS_ENUM(NSInteger ,PXRPWalletKYCFromType) {
    PXRPWalletKYCFromTypeFromTypeNextTime = 10,//有nextTime
    PXRPWalletKYCFromTypeFromVerity //校验verify
};
@protocol PXRPPayByWalletDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface PXRPPayByWalletInterface : NSObject

+ (instancetype)shareInstance;


+ (void)walletPageOnViewController:(UIViewController *)vc;



/// KYC 认证检测
/// @param vc vc VC。如果VC 为nil ，只做检测 并返回 model ，如果有VC 则检测与跳转一起 并返回model
/// @param type VC 情况下有用，界面是否显示NEXTTIME 或只展示 verify
/// @param success <#success description#>
/// @param fail <#fail description#>
+ (void)WalletKYCController:(UIViewController *__nullable)vc andFrom:(PXRPWalletKYCFromType)type andSuccess:(void(^)(PXRPKYCStatusInfoModel *model))success andFail:(void(^)(NSError *error))fail;

/// 查询会员状态 – 用于静默登录后判断是否核需要身验证
/// @param vc 当前VC
/// @param result <#success description#>
+ (void)memberStatusQuery:(UIViewController *)vc andSuccess:(void(^)(BOOL isSuccess,NSString *errorMsg))result;

#pragma mark - 付款码页面

+ (UIViewController *)payByPayCodePageOnViewContorllerWithCashierConfirmAppear:(void(^)(BOOL hiddenTabbar,id obj))cashierConfirmAppear;

#pragma mark - 显示钱包页面

/// 钱包功能模块
/// @param vc vc push
/// @param type 功能类型
+ (void)pushWalletPageOnViewController:(UIViewController *)vc andFunType:(PXRPWalletFunType)type ;


/// webview URL
/// @param vc vc
/// @param url url
+ (void)pushWalletWebPageOnViewController:(UIViewController *)vc andWebUrl:(NSString *)url andToken:(NSString *)token;


/// 获取余额 list
+ (void)getWalletPageBanlance:(void(^)(NSArray *accountList))success andFail:(void(^)(NSError *error))fail;
@end


/* ------------------------------------------- */

@protocol PXRPPayByWalletDelegate <NSObject>



@optional

/// kyc eid 认证 回调
/// @param success yes 成功 no 失败
/// @param msg <#msg description#>
- (void)PXRPPayByWalletEidVerityResult:(BOOL)success andMsg:(NSString *)msg;

/// 忘记密码回调
/// @param success yes 成功 no 失败
/// @param msg <#msg description#>
- (void)PXRPPayByForgetPasswordResult:(BOOL)success andMsg:(NSString *)msg;

@end
NS_ASSUME_NONNULL_END
