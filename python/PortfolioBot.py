from telegram.ext.updater import Updater
from telegram.update import Update
from telegram.ext.callbackcontext import CallbackContext
from telegram.ext.commandhandler import CommandHandler
from telegram.ext.messagehandler import MessageHandler
from telegram.ext.filters import Filters

updater = Updater("Your Bot API that you got from BotFather", use_context=True)

def start(update: Update, context: CallbackContext):
    update.message.reply_text("Hello, I am {Your Name}, I am specialised in ...... Loving the process as much as the outcome, I take a collabrative, creative and strategic approach to solving problems. For further contact me, type the command /contact for connecting with my social links")

def contact(update: Update, context: CallbackContext):
    update.message.reply_text("""Available Commands :- 
    /github - To see my other repos
    /linkedin - To see my LinkedIn page
    /gmail - To write me
    /instagram - To have a glance of my life
    /twitter - To see my views of the world issues""")

def gmail_url(update: Update, context: CallbackContext):
    update.message.reply_text("mailto:your_email_ID")

def linkedin_url(update: Update, context: CallbackContext):
    update.message.reply_text("link to linkedIn")

def github_url(update: Update, context: CallbackContext):
    update.message.reply_text("link to github")

def instagram_url(update: Update, context: CallbackContext):
    update.message.reply_text("link to instagram")
    
def twitter_url(update: Update, context: CallbackContext):
  update.message.reply_text("link to twitter account")    

def unknown(update: Update, context: CallbackContext):
    update.message.reply_text("Sorry '%s' is not a valid command" % update.message.text)

def unknown_text(update: Update, context: CallbackContext):
    update.message.reply_text("Sorry I can't recognize you, you said '%s'" % update.message.text)


updater.dispatcher.add_handler(CommandHandler('start', start))
updater.dispatcher.add_handler(CommandHandler('contact', contact)) 
updater.dispatcher.add_handler(CommandHandler('github', github_url))
updater.dispatcher.add_handler(CommandHandler('linkedin', linkedin_url))
updater.dispatcher.add_handler(CommandHandler('gmail', gmail_url))
updater.dispatcher.add_handler(CommandHandler('instagram', instagram_url))
updater.dispatcher.add_handler(CommandHandler('twitter', twitter_url))
updater.dispatcher.add_handler(MessageHandler(Filters.text, unknown))
updater.dispatcher.add_handler(MessageHandler(Filters.command, unknown))
updater.dispatcher.add_handler(MessageHandler(Filters.text, unknown_text))

updater.start_polling()
