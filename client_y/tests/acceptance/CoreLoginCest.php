<?php

class CoreLoginCest {

  public function loginSuccessful(AcceptanceTester $I) {
    $I->wantTo('Log in');
    $I->amOnPage('/user/login');
    $I->fillField('#edit-name', 'admin');
    $I->fillField('#edit-pass', 'admin1');
    $I->click('//form[@id=\'user-login-form\']//button[@id=\'edit-submit\']');
    $I->seeCurrentUrlMatches('~/user/(\d+)~');
    $I->dontSeeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-danger\']');
    $I->dontSee('Unrecognized username or password. Forgot your password?');
    $I->dontSeeLink('Forgot your password?');
    $I->seeElement('#block-breadcrumbs');
    $I->see('Drupal8.pl admin');
  }

  public function logoutSuccessful(AcceptanceTester $I) {
    $I->wantTo('Log out');
    $I->amOnPage('/user/login');
    $I->fillField('#edit-name', 'admin');
    $I->fillField('#edit-pass', 'admin1');
    $I->click('//form[@id=\'user-login-form\']//button[@id=\'edit-submit\']');
    $I->seeCurrentUrlMatches('~/user/(\d+)~');
    $I->dontSeeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-danger\']');
    $I->dontSee('Unrecognized username or password. Forgot your password?');
    $I->dontSeeLink('Forgot your password?');
    $I->seeElement('#block-breadcrumbs');
    $I->see('Drupal8.pl admin');
    $I->click('Log out');
    $I->seeCurrentURLEquals('/');
    $I->dontSee('Drupal8.pl admin');
  }

  public function loginUnsuccessful(AcceptanceTester $I) {
    $I->wantTo('Login unsuccessfully');
    $I->amOnPage('/user/login');
    $I->fillField('#edit-name', 'test3drupal8testpl');
    $I->fillField('#edit-pass', 'test3drupal8testpl');
    $I->click('Log in', '//form[@id=\'user-login-form\']//button[@id=\'edit-submit\']');
    $I->seeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-danger\']');
    $I->see('Unrecognized username or password. Forgot your password?');
    $I->click('Forgot your password?');
    $I->seeCurrentURLEquals('/user/password?name=test3drupal8testpl');
  }

  public function ResetYourPassword(AcceptanceTester $I) {
    $I->wantTo('Reset password');
    $I->amOnPage('/user/password');
    $I->see('Username or email address');
    $I->fillField('#edit-name', 'ogrysh');
    $I->see('Password reset instructions will be sent to your registered email address.');
    $I->click('//form[@id=\'user-pass\']//button[@id=\'edit-submit\']');
    $I->seeCurrentURLEquals('/user/login');
//    $I->dontSeeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-danger\']');
  }

  public function CreateNewAccount(AcceptanceTester $I) {
    $I->wantTo('Create new account');
    $I->amOnPage('/user/register');
    $I->see('Create new account');
    $I->seeElement('#user-register-form');
    $I->see('Email address');
    $I->fillField('#edit-mail', 'test2@drupal8test.pl');
    $I->see('A valid email address. All emails from the system will be sent to this address. The email address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by email.');
    $I->seeElement('#edit-mail--description');
    $I->see('Username');
    $I->fillField('#edit-name', 'test2drupal8testpl');
    $I->seeElement('#edit-name--description');
    $I->see('Several special characters are allowed, including space, period (.), hyphen (-), apostrophe (\'), underscore (_), and the @ sign.');
    $I->see('Locale settings');
    $I->see('Time zone');
    $I->seeElement('#edit-timezone');
    $I->selectOption('timezone', 'Europe/Warsaw');
    $I->see('Select the desired local time and time zone. Dates and times throughout this site will be displayed using this time zone.');
    $I->seeElement('#edit-timezone--2--description');
    $I->click('//form[@id=\'user-register-form\']//button[@id=\'edit-submit\']');
    $I->seeCurrentURLEquals('/');
    $I->seeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-success\']');
  }

  public function CreateNewExistingAccount(AcceptanceTester $I) {
    $I->wantTo('Create new existing account');
    $I->amOnPage('/user/register');
    $I->see('Create new account');
    $I->seeElement('#user-register-form');
    $I->see('Email address');
    $I->fillField('#edit-mail', 'test2@drupal8test.pl');
    $I->see('A valid email address. All emails from the system will be sent to this address. The email address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by email.');
    $I->seeElement('#edit-mail--description');
    $I->see('Username');
    $I->fillField('#edit-name', 'test2drupal8testpl');
    $I->seeElement('#edit-name--description');
    $I->see('Several special characters are allowed, including space, period (.), hyphen (-), apostrophe (\'), underscore (_), and the @ sign.');
    $I->see('Locale settings');
    $I->see('Time zone');
    $I->seeElement('#edit-timezone');
    $I->selectOption('timezone', 'Europe/Warsaw');
    $I->see('Select the desired local time and time zone. Dates and times throughout this site will be displayed using this time zone.');
    $I->seeElement('#edit-timezone--2--description');
    $I->click('//form[@id=\'user-register-form\']//button[@id=\'edit-submit\']');
    $I->seeCurrentURLEquals('/user/register');
    $I->seeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-danger\']');
    $I->dontSeeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-success\']');
  }

  public function DeleteNewAccount(AcceptanceTester $I) {
    $I->wantTo('Delete new account');
    //Login
    $I->amOnPage('/user/login');
    $I->fillField('#edit-name', 'admin');
    $I->fillField('#edit-pass', 'admin1');
    $I->click('//form[@id=\'user-login-form\']//button[@id=\'edit-submit\']');
    $I->seeCurrentUrlMatches('~/user/(\d+)~');
    $I->dontSeeElement('//div[@class=\'alert alert-dismissible fade show col-12 alert-danger\']');
    $I->dontSee('Unrecognized username or password. Forgot your password?');
    $I->dontSeeLink('Forgot your password?');
    $I->seeElement('#block-breadcrumbs');
    $I->see('Drupal8.pl admin');
    //Delete
    $I->amOnPage('/admin/people');
    $I->click('test2drupal8testpl');
    $I->seeCurrentUrlMatches('~/user/(\d+)~');
    $I->click('//a[@class=\'nav-link\'][contains(text(),\'Edit\')]');
    $I->seeCurrentUrlMatches('~/user/(\d+)/edit~');
    $I->click('//input[@id=\'edit-delete\']');
    $I->seeCurrentUrlMatches('~/user/(\d+)/cancel~');
    $I->fillField('user_cancel_method', 'user_cancel_delete');
    $I->click('//input[@id=\'edit-submit\']');
    $I->seeCurrentURLEquals('/admin/people');
    $I->see('test2drupal8testpl has been deleted.');
    //Log out
    $I->amOnPage('/user/1');
    $I->seeElement('#block-breadcrumbs');
    $I->see('Drupal8.pl admin');
    $I->click('Log out');
    $I->seeCurrentURLEquals('/');
    $I->dontSee('Drupal8.pl admin');
  }
}

?>
