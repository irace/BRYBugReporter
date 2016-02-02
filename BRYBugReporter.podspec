Pod::Spec.new do |s|
  s.name = 'BRYBugReporter'
  s.version = '0.2.0'
  s.summary = 'A fork of Marco Arment’s BugshotKit that isn’t coupled to `MFMailComposeViewController`'
  s.homepage = 'https://github.com/irace/BRYBugReporter'
  s.license = { :type => 'MIT', :file => 'LICENSE' }
  s.author = { 'Marco Arment' => 'arment@marco.org' }
  s.source = { :git => 'https://github.com/irace/BRYBugReporter.git', :tag => s.version.to_s }
  s.source_files  = 'BugshotKit/*.{h,m}'
  s.resource  = [ 'Resources/*' ]
  s.requires_arc = true
  s.ios.deployment_target = '9.0'
end
