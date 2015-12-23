//  BSKMainViewController.h
//  See included LICENSE file for the (MIT) license.
//  Created by Marco Arment on 1/17/14.

#import <UIKit/UIKit.h>
@class BSKSubmission;
@class BSKMainViewController;

@protocol BSKMainViewControllerDelegate

- (void)mainViewController:(BSKMainViewController *)mainViewController didSubmit:(BSKSubmission *)submission;

- (void)mainViewControllerDidClose:(BSKMainViewController *)mainViewController;

@end


@interface BSKMainViewController : UITableViewController

@property (nonatomic, weak) id<BSKMainViewControllerDelegate> delegate;

@end
