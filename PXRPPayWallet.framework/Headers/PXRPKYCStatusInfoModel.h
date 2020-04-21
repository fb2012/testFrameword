//
//  PXRPKYCStatusInfoModel.h
//  PXRPPayWallet
//
//  Created by ice on 2020/4/8.
//  Copyright © 2020 ice. All rights reserved.
//

#import <Foundation/Foundation.h>



typedef NS_ENUM(NSInteger ,PXRPKYCVerityStatus) {
    PXRPKYCVerityStatusE_KYCNomal,//未实名
    PXRPKYCVerityStatusE_KYC,  //OCR&ICA）
    PXRPKYCVerityStatusFULL_KYC,//（活体识别
    PXRPKYCVerityStatusFINISH_KYC,//（流程全部完成
    PXRPKYCVerityStatusVIP_KYC,//VIP用户默认）
    PXRPKYCVerityStatusEXPIRED_KYC //过期备用）
};



/// StatusModel
@interface PXRPKYCStatusInfoModel : NSObject

/// 会员编号
@property(copy ,nonatomic)NSString *memberId;

/// 用户统一编号
@property(copy ,nonatomic)NSString *unifiedNo;

/// 真实姓名
@property(copy ,nonatomic)NSString *name;

/// 真实姓名密钥
@property(copy ,nonatomic)NSString *nameTicket;

/// 身份证号号（7*********1）
@property(copy ,nonatomic)NSString *idNumber;

/// 身份证号号密文
@property(copy ,nonatomic)NSString *dNumberTicket;

/// 阿拉伯名称
@property(copy ,nonatomic)NSString *nameArabic;

/// 英文姓名（XU******）
@property(copy ,nonatomic)NSString *nameEnglish;

/// 英文名称密文
@property(copy ,nonatomic)NSString *nameEnglishTicket;

/// 性别 ''-保密 0-女性 1-男性
@property(copy ,nonatomic)NSString *gender;

/// 生日
@property(copy ,nonatomic)NSString *birthDate;

/// 网纹照
@property(copy ,nonatomic)NSString *photo;

/// 国别
@property(copy ,nonatomic)NSString *nationality;

/// 国别描述
@property(copy ,nonatomic)NSString *nationalityDesc;

/// 宗教信仰
@property(copy ,nonatomic)NSString *religion;

/// 婚姻状态： ''-未知 1-已婚 2-未婚
@property(copy ,nonatomic)NSString *maritalstatus;

/// E_KYC（OCR&ICA），FULL_KYC（活体识别），FINISH_KYC（流程全部完成），VIP_KYC（VIP用户默认），EXPIRED_KYC（过期备用）
//@property(copy ,nonatomic)NSString *kycStatus;
@property(assign ,nonatomic)PXRPKYCVerityStatus kysStatus;

/// 展示状态
@property(copy ,nonatomic) NSString *kysStatusShow;

/// 生效日期
@property(copy ,nonatomic)NSString *effectTime;

/// 失效日期
@property(copy ,nonatomic)NSString *invalidTime;


/// 状态信息描述
@property(copy ,nonatomic)NSString *statusMsg;
@end

