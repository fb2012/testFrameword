:Pod::Spec.new do |s|
    s.name         = "testFrameword"
    s.version      = "1.0."
    s.ios.deployment_target = '8.0'
    s.summary      = "testsdk,一个简单的testSDK."
    s.homepage     = "https://github.com/fb2012/testFrameword"
    s.license              = { :type => "MIT", :file => "LICENSE" }
    s.author             = { "Simple" => "810646506@qq.com" }
    s.source       = { :git => "https://github.com/fb2012/testFrameword.git", :tag => s.version }
    s.source_files  = "PXRPPayWallet.framework/Headers/*.{h}"
    s.resources          = "PXRPPayWalletResource.bundle","FidoTable.bundle","SIPKeyboardBundle.bundle"
    s.frameworks = 'Foundation', 'UIKit'
    s.vendored_frameworks = 'PXRPPayWallet.framework'
    #SDK头文件路径
     s.public_header_files = 'PXRPPayWallet.framework/Headers/*.{h}'
    s.requires_arc = true
end

