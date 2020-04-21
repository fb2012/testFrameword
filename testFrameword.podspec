Pod::Spec.new do |s|

#名称
s.name         = 'testFrameword'

#版本号
s.version      = '0.0.3'

#许可证
s.license      = { :type => 'MIT' }

#项目主页地址
s.homepage     = 'https://github.com/fb2012/testFrameword'

#作者
s.authors      = { '无星' => 'wuxing@bjca.org.cn' }

#简介
s.summary      = "北京签名SDK"

#项目的地址 （注意这里的tag位置，可以自己写也可以直接用s.version，但是与s.version一定要统一）
s.source       = { :git => 'https://github.com/fb2012/testFrameword.git', :tag => s.version }

#支持最小系统版本
s.platform     = :ios, '9.0'

#需要包含的源文件
s.source_files = 'PXRPPayWallet.framework/Headers/*.{h}'
s.resources    = "PXRPPayWalletResource.bundle","FidoTable.bundle","SIPKeyboardBundle.bundle"
#你的SDK路径
s.vendored_frameworks = 'PXRPPayWallet.framework'

#SDK头文件路径
s.public_header_files = 'PXRPPayWallet.framework/Headers/*.{h}'

#依赖库
#s.libraries    = 'sqlite3','icucore','z'

#依赖库
s.frameworks   = 'UIKit','Foundation'

end



