//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TSThread.h"

NS_ASSUME_NONNULL_BEGIN

@class Contact;
@class OWSContactsManager;

typedef enum : NSUInteger { kArchiveState = 0, kInboxState = 1 } CellState;

@interface InboxTableViewCell : UITableViewCell <UIScrollViewDelegate>

@property (nonatomic) IBOutlet UILabel *nameLabel;
@property (nonatomic) IBOutlet UILabel *snippetLabel;
@property (nonatomic) IBOutlet UIImageView *contactPictureView;
@property (nonatomic) IBOutlet UILabel *timeLabel;
@property (nonatomic) IBOutlet UIView *contentContainerView;
@property (nonatomic) IBOutlet UIView *messageCounter;
@property (nonatomic) NSString *threadId;
@property (nonatomic) NSString *contactId;

+ (instancetype)inboxTableViewCell;

+ (CGFloat)rowHeight;

- (void)configureWithThread:(TSThread *)thread
            contactsManager:(OWSContactsManager *)contactsManager
      blockedPhoneNumberSet:(NSSet<NSString *> *)blockedPhoneNumberSet;

// This method is used to present _possible_ threads - threads
// that will be created if this cell is selected.
- (void)configureWithContact:(Contact *)contact
                 recipientId:(NSString *)recipientId
             contactsManager:(OWSContactsManager *)contactsManager
                   isBlocked:(BOOL)isBlocked;

- (void)animateDisappear;

@end

NS_ASSUME_NONNULL_END
