//
//  BSKSubmission.h
//  BugshotKit
//
//  Created by Bryan Irace on 12/23/15.
//  Copyright © 2015 Marco Arment. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BSKSubmission : NSObject

@property (nonatomic, readonly, nonnull) NSString *appName;
@property (nonatomic, readonly, nonnull) NSString *appVersion;
@property (nonatomic, readonly, nonnull) NSString *modelIdentifier;
@property (nonatomic, readonly, nonnull) NSString *systemVersion;
@property (nonatomic, readonly, nonnull) UIImage *screenshot;
@property (nonatomic, readonly, nonnull) NSString *log;

- (nonnull instancetype)initWithAppName:(nonnull NSString *)appName appVersion:(nonnull NSString *)appVersion
                modelIdentifier:(nonnull NSString *)modelIdentifier systemVersion:(nonnull NSString *)systemVersion
                     screenshot:(nonnull UIImage *)screenshot log:(nonnull NSString *)log;

@end
