#
#  Be sure to run `pod spec lint TPhoneRTC.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#


Pod::Spec.new do |s|
  s.name         = "TPhoneRTC"
  s.version      = "1.1.10"
  s.summary      = "TPhoneRTC iOS实时语音呼叫SDK"

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'git@github.com:ti-net/TPhone-RTC-iOS.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'gyb1314' => 'gyb_1314@126.com' }
  s.source           = { :git => 'https://github.com/ti-net/TPhone-RTC-iOS.git', :tag => s.version.to_s }

 # s.ios.deployment_target = '9.0'
  s.platform     = :ios, "9.0"

  s.vendored_frameworks  = "TPhoneRTC.framework","TPhoneSDKCore.xcframework"
  s.pod_target_xcconfig = {'VALID_ARCHS'=>'arm64 x86_64 armv7','EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.dependency 'TiCloudRTC'

end