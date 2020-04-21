//
//  PXRPPayWalletObject.h
//  PXRPPayWallet
//
//  Created by Yaoxh on 13/11/2019.
//  Copyright © 2019 ice. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// SDK状态
typedef NS_ENUM(NSInteger, PXRPPayWalletStatus) {
    /// SDK不可用
    PXRPPayWalletStatusInvalidate,
    /// SDK正在登录
    PXRPPayWalletStatusLogining,
    /// SDK可正常使用
    PXRPPayWalletStatusWorking,
};

/// 交易货币类型
typedef NS_ENUM(NSInteger, PXRPPayMoneyCurrentcy) {
    /// 迪拉姆
    PXRPPayMoneyCurrentcyAED = 1,
    /// 人民币
    PXRPPayMoneyCurrentcyRMB = 2,
    /// 美元
    PXRPPayMoneyCurrentcyUSD = 3
};
/// 扫码的类型
typedef NS_ENUM(NSInteger, PXRPPayScanCodeType) {
    /// 不是PXRP code
    PXRPPayScanCodeTypeNo = 0,
    ///  PXRP  静态收款码 需要 tradeNo
    PXRPPayScanCodeTypeStatic ,
    ///  PXRP 支付码
    PXRPPayScanCodeTypeOther
};

//TODO: 错误码，待补充
typedef NS_ENUM(NSInteger, PXRPPayErrorCode) {
    PXRPPayErrorCodeNetwork = 0,
    PXRPPayErrorCodeAuthTokenExpire,
    PXRPPayErrorCodeNoUserInfo
};
//转账接受状态
typedef NS_ENUM(NSInteger, PXRPPTransferReceivedStatus) {
    PXRPPTransferReceivedStatusFinish = 2,//已接受
    PXRPPTransferReceivedStatusRefund,//拒绝
    PXRPPTransferReceivedStatusFailed,// 转账接受失败
    PXRPPTransferReceivedStatusProcessing,//领取中
    PXRPPTransferReceivedStatusOutTime//超时

};

/// 红包领取状态
typedef NS_ENUM(NSInteger, PXRPPRedPacketReceiveStatus) {
    PXRPPRedPacketReceiveStatusOpened = 1,
    PXRPPRedPacketReceiveStatusCanOpen, //红包可领取
    PXRPPRedPacketReceiveStatusComplete,    //红包已全部领完
    PXRPPRedPacketReceiveStatusRefund,      //红包已退款
};

/// 红包类型
typedef NS_ENUM(NSInteger, PXRPPRedPacketType) {
    PXRPPRedPacketTypeLucky = 0,
    PXRPPRedPacketTypeAverage,
};
typedef NS_ENUM(NSInteger, PXRPPayTradeNoType) {
    PXRPPayTradeNoTypeRedPacket,//红包
    PXRPPayTradeNoTypeTransfer//转账
};

/// PXRPPay用户数据
@interface PXRPPayUser : NSObject
/// 用户Id
@property (strong, nonatomic) NSString *userId;
/// 用户登录token
@property (strong, nonatomic) NSString *accessToken;
/// 用户名字
@property (strong, nonatomic) NSString *name;

/// 用户电话（可选）
@property (strong, nonatomic) NSString *phone;
/// 用户头像 （可选） 优先取 头像
@property (strong, nonatomic) UIImage *avatar;

/// 用户头像地址 （可选）
@property (strong, nonatomic) NSString *avatarLink;

@end

/* ------------------------------------------- */
/// PXRPPay 付款码支付结果
@class PXRPPayMoney;
@interface PXRPPayPaymentResult : NSObject
/// 交易Id
@property (nonatomic, strong) NSString *tradeNo;
///交易金额
@property (nonatomic, strong) PXRPPayMoney *amount;

/// 是否成功
@property (nonatomic) BOOL succeed;
/// 失败原因
@property (nonatomic, strong) NSString *reason;

@end

/* ------------------------------------------- */
/// PXRPPay 转账结果
@interface PXRPPayTransferResult : NSObject
/// 交易Id
@property (strong, nonatomic) NSString *tradeNo;
/// 交易金额
@property (nonatomic, strong) PXRPPayMoney *amount;
/// 发起用户Id
@property (strong, nonatomic) NSString *fromUserId;
/// 接收用户Id
@property (strong, nonatomic) NSString *toUserId;

/// 转账备注
@property(copy, nonatomic)NSString *remark;

/// 转账领取的状态
@property(assign, nonatomic)PXRPPTransferReceivedStatus receivedStatus;

/// 是否成功
@property (nonatomic) BOOL succeed;
/// 失败原因
@property (nonatomic, strong) NSString *reason;

@end

/* ------------------------------------------- */
/// PXRPPay 红包结果
@interface PXRPPayRedPacketResult : NSObject
/// 交易Id
@property (strong, nonatomic) NSString *tradeNo;
/// 交易金额
@property (nonatomic, strong) PXRPPayMoney *amount;
/// 红包个数
@property (nonatomic, strong) NSNumber *number;
/// 红包类型
@property (nonatomic) PXRPPRedPacketType type;
/// 红包备注信息
@property (nonatomic, strong) NSString *remark;
/// 红包领取状态
@property (nonatomic, assign) PXRPPRedPacketReceiveStatus status;

/// 是否成功
@property (nonatomic) BOOL succeed;
/// 失败原因
@property (nonatomic, strong) NSString *reason;

@end

/* ------------------------------------------- */
/// PXRPPay 货币金额
@interface PXRPPayMoney : NSObject
/// 金额
@property (strong, nonatomic) NSNumber *amount;
/// 货币类型  改为 string 
@property (copy,nonatomic) NSString *current;

@end

/* ------------------------------------------- */
/// PXRPPay 群组数据
@interface PXRPPayGroup : NSObject
/// 群Id
@property (nonatomic, strong) NSString *groupId;
/// 群总人数
@property (nonatomic, strong) NSNumber *memberCount;

@end

@interface PXRPPErrorInfo : NSObject

@end



NS_ASSUME_NONNULL_END
