/*
  Custom configuration for ckeditor.

  Configuration options can be set here. Any settings described here will be
  overridden by settings defined in the $settings variable of the hook. To
  override those settings, do it directly in the hook itself to $settings.
*/
CKEDITOR.editorConfig = function (config) {
  /**
   * The list of fonts size to be displayed in the Font Size combo in the
   * toolbar. Entries are separated by semi-colons (`';'`).
   *
   * Any kind of "CSS like" size can be used, like `'12px'`, `'2.3em'`,
   * `'130%'`,
   * `'larger'` or `'x-small'`.
   *
   * A display name may be optionally defined by prefixing the entries with
   * the name and the slash character. For example, `'Bigger Font/14px'`
   * will be displayed as `'Bigger Font'` in the list, but will be
   * outputted as
   * `'14px'`.
   *
   *    config.fontSize_sizes = '16/16px;24/24px;48/48px;';
   *
   *    config.fontSize_sizes = '12px;2.3em;130%;larger;x-small';
   *
   *    config.fontSize_sizes = '12 Pixels/12px;Big/2.3em;30 Percent
   * More/130%;Bigger/larger;Very Small/x-small';
   *
   * @cfg {String} [fontSize_sizes=see source]
   * @member CKEDITOR.config
   */
  config.fontSize_sizes = '60px/3.75rem;40px/2.5rem;30px/1.875rem;26px/1.625rem;26/26px;24px/1.5rem;20px/1.25rem;16px/1rem;15px/0.9375rem;14px/0.875rem;13px/0.8125rem;12px/0.75rem;11px/0.6875rem'
}