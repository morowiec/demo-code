<?php

/**
 * @file
 * Important date template file.
 *
 * @ingroup views_templates
 */
?>
<ul class="list-group">
  <?php foreach ($fields as $field): ?>
    <li class="list-group-item">
      <?php print $field['label']; ?>: <strong><?php print $field['value']; ?></strong>
    </li>
  <?php endforeach; ?>
</ul>
