//
//  BSKSubmission.m
//  BugshotKit
//
//  Created by Bryan Irace on 12/23/15.
//  Copyright © 2015 Marco Arment. All rights reserved.
//

#import "BSKSubmission.h"

@implementation BSKSubmission

- (nonnull instancetype)initWithAppName:(nonnull NSString *)appName appVersion:(nonnull NSString *)appVersion
                        modelIdentifier:(nonnull NSString *)modelIdentifier systemVersion:(nonnull NSString *)systemVersion
                             screenshot:(nonnull UIImage *)screenshot log:(nonnull NSString *)log {
    self = [super init];
    if (self) {
        _appName = [appName copy];
        _appVersion = [appVersion copy];
        _modelIdentifier = [modelIdentifier copy];
        _systemVersion = [systemVersion copy];
        _screenshot = screenshot;
        _log = [log copy];
    }
    
    return self;
}

@end
