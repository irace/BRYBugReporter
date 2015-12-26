Pod::Spec.new do |s|
  s.name = 'BugshotKit'
  s.version = '0.1.0'
  s.summary = 'In-app bug reporting for developers and testers, with annotated screenshots and the console log.'
  s.homepage = 'https://github.com/irace/BugshotKit'
  s.license = { :type => 'MIT', :file => 'LICENSE' }
  s.author = { 'Marco Arment' => 'arment@marco.org' }
  s.source = { :git => 'https://github.com/irace/BugshotKit.git', :tag => s.version.to_s }
  s.source_files  = 'BugshotKit/*.{h,m}'
  s.resource  = [ 'Resources/*' ]
  s.requires_arc = true
  s.ios.deployment_target = '9.0'
end