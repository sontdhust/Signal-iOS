//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

@class TSThread;

NS_ASSUME_NONNULL_BEGIN

@protocol SelectThreadViewControllerDelegate <NSObject>

- (void)threadWasSelected:(TSThread *)thread;

- (BOOL)canSelectBlockedContact;

- (nullable UIView *)createHeaderWithSearchBar:(UISearchBar *)searchBar;

@end

#pragma mark -

@interface SelectThreadViewController : UIViewController

@property (nonatomic, weak) id<SelectThreadViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
